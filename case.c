/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:27 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/14 15:07:57 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_three_case	ft_three_case(t_list *a)
{
	if (*((int *) a->content) < *((int *) a->next->content))
	{
		if (*((int *) a->content) < *((int *) a->next->next->content))
			return (CASE_SLM);
		return (CASE_MLS);
	}
	if (*((int *) a->content) < *((int *) a->next->next->content))
		return (CASE_MSL);
	if (*((int *) a->next->content) < *((int *) a->next->next->content))
		return (CASE_LSM);
	return (CASE_LMS);
}

static void	ft_sort_three(t_list **a, t_list **b)
{
	t_three_case	three_case;

	if (ft_lstsize(*a) == 2)
	{
		ft_run_op(a, b, RA);
		return ;
	}
	three_case = ft_three_case(*a);
	if (three_case == CASE_SLM)
	{
		ft_run_op(a, b, RRA);
		ft_run_op(a, b, SA);
	}
	else if (three_case == CASE_MLS)
		ft_run_op(a, b, RRA);
	else if (three_case == CASE_MSL)
		ft_run_op(a, b, SA);
	else if (three_case == CASE_LSM)
		ft_run_op(a, b, RA);
	else if (three_case == CASE_LMS)
	{
		ft_run_op(a, b, RA);
		ft_run_op(a, b, SA);
	}
}

void	ft_case_five(t_list **a, t_list **b, int pivot)
{
	t_op	op;

	if (ft_lstsize(*a) == 5)
	{
		ft_start_inner(a, b, pivot, 2);
		if (*((int *)(*b)->content) < *((int *)(*b)->next->content))
			ft_run_op(a, b, RB);
	}
	else if (ft_lstsize(*a) == 4)
	{
		ft_init_op(&op, ft_lstmin(*a));
		ft_set_op(&op, *a, *b);
		ft_run_op_n(a, b, op.a, op.a_c);
		ft_run_op(a, b, PB);
	}
	if (!ft_is_sorted(*a))
		ft_sort_three(a, b);
}
