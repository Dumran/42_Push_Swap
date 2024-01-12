/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:29 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/12 11:12:00 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"

static void	ft_reverse(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	tmp = *stack;
	*stack = last;
	last->next = tmp;
}

void	ft_rra(t_list **a)
{
	ft_reverse(a);
}

void	ft_rrb(t_list **b)
{
	ft_reverse(b);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_reverse(a);
	ft_reverse(b);
}
