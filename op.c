/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:42 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/14 15:06:32 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_op(t_op *op, t_list *a, t_list *b)
{
	t_min_op_cost	moc;

	ft_cal_op_cost(op, a, b);
	moc = ft_get_min_op_cost(&op->cost);
	op->total_c = moc.cost;
	if (moc.comb == C_RA_RB)
	{
		ft_set_op_type(op, RA, RB, RR);
		ft_set_op_counts(op, C_RA_RB);
	}
	else if (moc.comb == C_RA_RRB)
	{
		ft_set_op_type(op, RA, RRB, NONE);
		ft_set_op_counts(op, C_RA_RRB);
	}
	else if (moc.comb == C_RRA_RB)
	{
		ft_set_op_type(op, RRA, RB, NONE);
		ft_set_op_counts(op, C_RRA_RB);
	}
	else if (moc.comb == C_RRA_RRB)
	{
		ft_set_op_type(op, RRA, RRB, RRR);
		ft_set_op_counts(op, C_RRA_RRB);
	}
}

void	ft_run_op(t_list **a, t_list **b, t_op_type ot)
{
	if (ot == RA)
		ft_ra(a);
	else if (ot == RRA)
		ft_rra(a);
	else if (ot == RB)
		ft_rb(b);
	else if (ot == RRB)
		ft_rrb(b);
	else if (ot == RR)
		ft_rr(a, b);
	else if (ot == RRR)
		ft_rrr(a, b);
	else if (ot == PB)
		ft_pb(a, b);
	else if (ot == PA)
		ft_pa(a, b);
	else if (ot == SA)
		ft_sa(a);
}

void	ft_run_op_n(t_list **a, t_list **b, t_op_type op_type, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		ft_run_op(a, b, op_type);
}

static t_op	ft_get_optimum_op(t_op *ops, int size)
{
	t_op	min;
	int		i;

	i = 0;
	min.total_c = INT32_MAX;
	while (i < size)
	{
		if (min.total_c >= ops[i].total_c)
		{
			min = ops[i];
		}
		i++;
	}
	return (min);
}

t_op	ft_select_op(t_list *a, t_list *b, int pivot)
{
	t_op	*ops;
	t_op	min;
	int		pass_count;
	int		i;
	t_list	*tmp;

	pass_count = ft_count_passenger(a, pivot);
	ops = (t_op *) malloc(sizeof(t_op) * pass_count);
	if (!ops)
		(ft_dispose(b), ft_exiterr(14, a));
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (*((int *) tmp->content) < pivot)
		{
			ft_init_op(&ops[i], *((int *) tmp->content));
			ft_set_op(&ops[i++], a, b);
		}
		tmp = tmp->next;
	}
	min = ft_get_optimum_op(ops, pass_count);
	return (free(ops), min);
}
