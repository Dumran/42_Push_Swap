/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:18 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:20 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_ra(t_list **a)
{
	if (*a)
		ft_rotate(a);
}

void	ft_rb(t_list **b)
{
	if (*b)
		ft_rotate(b);
}

void	ft_rr(t_list **a, t_list **b)
{
	if (*a)
		ft_rotate(a);
	if (*b)
		ft_rotate(b);
}
