/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:24 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/12 10:59:17 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dispose(void *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = ((t_list *) stack)->next;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_exitsafe(void *stack, int exit_code)
{
	ft_dispose(stack);
	exit(exit_code);
}

void	ft_exiterr(int err_no, void *stack)
{
	ft_putendl_fd("Error", 2);
	ft_exitsafe(stack, err_no);
}

int	ft_lstmin(t_list *stack)
{
	int	min;

	min = INT32_MAX;
	while (stack)
	{
		if (min > *((int *) stack->content))
			min = *((int *) stack->content);
		stack = stack->next;
	}
	return (min);
}
