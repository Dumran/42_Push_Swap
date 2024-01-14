/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:23 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/14 15:33:40 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_param(int ac, char **av)
{
	int			i;
	long long	num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi_l(av[i]);
		if (num > INT32_MAX || num < INT32_MIN)
			ft_exiterr(7, NULL);
		if (num == 0 && ft_strncmp(av[i], "0", ft_strlen(av[i]) != 0))
			ft_exiterr(2, NULL);
		i++;
	}
}

int	ft_is_duplicate(t_list	*stack)
{
	t_list	*tmp;
	t_list	*curr;

	curr = stack;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (*((int *)curr->content) == *((int *)tmp->content))
				return (1);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	ft_is_sorted(t_list *stack)
{
	int	*prev;
	int	*curr;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		prev = (int *) stack->content;
		curr = (int *) stack->next->content;
		if (*prev > *curr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_init_list(char **inst_list)
{
	inst_list[0] = "rrr\n";
	inst_list[1] = "rra\n";
	inst_list[2] = "rrb\n";
	inst_list[3] = "rr\n";
	inst_list[4] = "pa\n";
	inst_list[5] = "pb\n";
	inst_list[6] = "sa\n";
	inst_list[7] = "sb\n";
	inst_list[8] = "ss\n";
	inst_list[9] = "ra\n";
	inst_list[10] = "rb\n";
}

int	ft_is_valid_inst(const char *inst)
{
	char	*inst_list[11];
	int		i;
	int		tmp;

	ft_init_list(inst_list);
	if (!inst)
		return (0);
	i = 0;
	while (i < 11)
	{
		tmp = ft_strncmp(inst_list[i], inst, ft_strlen(inst_list[i]));
		if (tmp == 0 && (ft_strlen(inst_list[i]) == ft_strlen(inst)))
			return (1);
		i++;
	}
	return (0);
}
