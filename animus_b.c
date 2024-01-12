/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animus_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:32 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:14:33 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_dest_val(t_list *b, int pass)
{
	t_list	*tmp;
	int		dest;
	int		state;

	dest = INT32_MIN;
	state = 1;
	tmp = b;
	while (tmp)
	{
		if (*((int *) tmp->content) < pass && *((int *) tmp->content) > dest)
		{
			dest = *((int *) tmp->content);
			state = 0;
		}
		tmp = tmp->next;
	}
	tmp = b;
	while (state && tmp)
	{
		if (dest < *((int *) tmp->content))
			dest = *((int *) tmp->content);
		tmp = tmp->next;
	}
	return (dest);
}

static int	ft_cal_rb_cost(t_list *b, int dest)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = b;
	while (tmp)
	{
		if (*((int *) tmp->content) == dest)
			break ;
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static int	ft_cal_rrb_cost(t_list *b, int dest)
{
	t_list	*tmp;
	int		count;
	int		state;

	count = 0;
	tmp = b;
	state = 1;
	while (tmp)
	{
		if (state && *((int *) tmp->content) != dest)
		{
			tmp = tmp->next;
			continue ;
		}
		if (*((int *) tmp->content) == dest)
		{
			tmp = tmp->next;
			state = 0;
			continue ;
		}
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	ft_cal_mov_b_op(t_list *b, int pass, int op)
{
	t_list	*tmp;
	int		dest;
	int		count;

	count = 0;
	if (b == NULL || ft_lstsize(b) == 1)
		return (count);
	dest = ft_find_dest_val(b, pass);
	if (op == RB)
		count = ft_cal_rb_cost(b, dest);
	else
	{
		count = ft_cal_rrb_cost(b, dest);
		count++;
	}
	return (count);
}
