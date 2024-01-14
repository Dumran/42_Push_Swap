/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:04 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/14 15:02:50 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_init_stack(int ac, char **av)
{
	t_list	*stack;
	t_list	*tmp;
	int		*val;
	int		i;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		val = (int *) malloc(sizeof(int));
		if (!val)
			ft_exiterr(3, stack);
		*val = ft_atoi(av[i]);
		tmp = ft_lstnew(val);
		if (!tmp)
		{
			free(val);
			ft_exiterr(4, stack);
		}
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	return (stack);
}

void	ft_start_inner(t_list **a, t_list **b, int pivot, int pass_count)
{
	t_op	op;
	int		i;

	i = 0;
	while (i < pass_count)
	{
		op = ft_select_op(*a, *b, pivot);
		ft_run_op_n(a, b, op.a, op.a_c);
		ft_run_op_n(a, b, op.b, op.b_c);
		ft_run_op_n(a, b, op.comm, op.comm_c);
		ft_run_op(a, b, PB);
		i++;
	}
}

static void	ft_prepare_a(t_list **a, t_list **b)
{
	int		min;
	int		min_op_cost;

	if (ft_is_sorted(*a))
		return ;
	min = ft_lstmin(*a);
	min_op_cost = ft_cal_mov_a_op(*a, min, RA);
	if (min_op_cost > ft_cal_mov_a_op(*a, min, RRA))
	{
		min_op_cost = ft_cal_mov_a_op(*a, min, RRA);
		ft_run_op_n(a, b, RRA, min_op_cost);
		return ;
	}
	ft_run_op_n(a, b, RA, min_op_cost);
}

static void	ft_start(t_list **a, t_list **b, int pass_count)
{
	int	pivot;

	if (ft_lstsize(*a) <= 5)
	{
		pivot = ft_get_pivot(*a);
		ft_case_five(a, b, pivot);
	}
	else if (ft_lstsize(*a) <= 475)
	{
		while (pass_count > 0)
		{
			pivot = ft_get_pivot(*a);
			pass_count = ft_count_passenger(*a, pivot);
			ft_start_inner(a, b, pivot, pass_count);
		}
	}
	else
	{
		while (pass_count > 0)
		{
			pass_count = ft_count_passenger(*a, INT32_MAX);
			ft_start_inner(a, b, INT32_MAX, pass_count);
		}
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac <= 1)
		return (1);
	ft_check_param(ac, av);
	a = ft_init_stack(ac, av);
	if (!a)
		ft_exiterr(2, NULL);
	if (ft_is_duplicate(a))
		ft_exiterr(3, a);
	if (ft_is_sorted(a))
		ft_exitsafe(a, EXIT_SUCCESS);
	ft_start(&a, &b, 1);
	ft_run_op_n(&a, &b, PA, ft_lstsize(b));
	ft_prepare_a(&a, &b);
	ft_dispose(a);
}
