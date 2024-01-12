/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:09 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:11 by mehkekli         ###   ########.fr       */
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
	if (*a)
		ft_swap(a);
}

void	ft_sb(t_list **b)
{
	if (*b)
		ft_swap(b);
}

void	ft_ss(t_list **a, t_list **b)
{
	if (*a)
		ft_swap(a);
	if (*b)
		ft_swap(b);
}
