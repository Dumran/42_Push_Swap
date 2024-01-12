/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:03 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:05 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"

static void	ft_swap(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_sa(t_list **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_list **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
