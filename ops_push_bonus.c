/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:13:38 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:39 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"

static void	ft_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	ft_pa(t_list **a, t_list **b)
{
	ft_push(b, a);
}

void	ft_pb(t_list **a, t_list **b)
{
	ft_push(a, b);
}
