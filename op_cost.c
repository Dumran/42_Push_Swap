/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:51 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:52 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cal_op_cost(t_op *op, t_list *a, t_list *b)
{
	op->cost.c_ra = ft_cal_mov_a_op(a, op->pass, RA);
	op->cost.c_rra = ft_cal_mov_a_op(a, op->pass, RRA);
	op->cost.c_rb = ft_cal_mov_b_op(b, op->pass, RB);
	op->cost.c_rrb = ft_cal_mov_b_op(b, op->pass, RRB);
}

static t_min_op_cost	ft_min_op_cost(int c_ra_rb, int c_rra_rb,
	int c_ra_rrb, int c_rra_rrb)
{
	t_min_op_cost	moc;

	moc.cost = INT32_MAX;
	if (c_ra_rb <= moc.cost)
	{
		moc.cost = c_ra_rb;
		moc.comb = C_RA_RB;
	}
	if (c_ra_rrb <= moc.cost)
	{
		moc.cost = c_ra_rrb;
		moc.comb = C_RA_RRB;
	}
	if (c_rra_rb <= moc.cost)
	{
		moc.cost = c_rra_rb;
		moc.comb = C_RRA_RB;
	}
	if (c_rra_rrb <= moc.cost)
	{
		moc.cost = c_rra_rrb;
		moc.comb = C_RRA_RRB;
	}
	return (moc);
}

t_min_op_cost	ft_get_min_op_cost(t_op_cost *cost)
{
	int	c_ra_rb;
	int	c_rra_rb;
	int	c_ra_rrb;
	int	c_rra_rrb;

	c_ra_rb = cost->c_ra;
	if (c_ra_rb < cost->c_rb)
		c_ra_rb = cost->c_rb;
	c_rra_rb = cost->c_rra + cost->c_rb;
	c_ra_rrb = cost->c_ra + cost->c_rrb;
	c_rra_rrb = cost->c_rra;
	if (c_rra_rrb < cost->c_rrb)
		c_rra_rrb = cost->c_rrb;
	return (ft_min_op_cost(c_ra_rb, c_rra_rb, c_ra_rrb, c_rra_rrb));
}

int	ft_count_passenger(t_list *a, int pivot)
{
	int	count;

	count = 0;
	while (a)
	{
		if (*((int *)a->content) < pivot)
			count++;
		a = a->next;
	}
	return (count);
}
