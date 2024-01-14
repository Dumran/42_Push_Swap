/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:13 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/14 15:16:12 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_op_type	ft_detect_op(char *inst)
{
	if (ft_strncmp(inst, "rrr\n", 4) == 0)
		return (RRR);
	if (ft_strncmp(inst, "rra\n", 4) == 0)
		return (RRA);
	if (ft_strncmp(inst, "rrb\n", 4) == 0)
		return (RRB);
	if (ft_strncmp(inst, "rr\n", 3) == 0)
		return (RR);
	if (ft_strncmp(inst, "ra\n", 3) == 0)
		return (RA);
	if (ft_strncmp(inst, "rb\n", 3) == 0)
		return (RB);
	if (ft_strncmp(inst, "pa\n", 3) == 0)
		return (PA);
	if (ft_strncmp(inst, "pb\n", 3) == 0)
		return (PB);
	if (ft_strncmp(inst, "ss\n", 3) == 0)
		return (SS);
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		return (SA);
	return (SB);
}

int	ft_run_instructions(t_list **a, t_list **b)
{
	char		*inst;
	t_op_type	ot;

	inst = get_next_line(STDIN_FILENO);
	if (!inst)
		return (-2);
	while (inst)
	{
		if (!ft_is_valid_inst(inst))
			return (free(inst), -1);
		ot = ft_detect_op(inst);
		ft_run_op(a, b, ot);
		free(inst);
		inst = get_next_line(STDIN_FILENO);
	}
	return (0);
}

void	ft_print_result(t_list *a)
{
	if (ft_is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		rsp;

	if (ac <= 1)
		return (1);
	ft_check_param(ac, av);
	a = ft_init_stack(ac, av);
	b = NULL;
	if (!a)
		ft_exiterr(2, NULL);
	if (ft_is_duplicate(a))
		ft_exiterr(3, a);
	rsp = ft_run_instructions(&a, &b);
	if (rsp == -1)
		return (ft_dispose(b), ft_exiterr(3, a), 3);
	if (rsp == -2)
		return (ft_print_result(a), ft_dispose(b), ft_dispose(a), 3);
	ft_print_result(a);
	ft_dispose(a);
	ft_dispose(b);
}
