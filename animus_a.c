/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animus_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:43 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:14:54 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cal_ra_cost(t_list *a, int pass)
{
	int	count;

	count = 0;
	while (a)
	{
		if (*((int *) a->content) == pass)
			break ;
		count++;
		a = a->next;
	}
	return (count);
}

static int	ft_cal_rra_cost(t_list *a, int pass)
{
	int		count;
	int		state;

	count = 0;
	state = 1;
	while (a)
	{
		if (state && *((int *) a->content) != pass)
		{
			a = a->next;
			continue ;
		}
		if (*((int *) a->content) == pass)
		{
			a = a->next;
			state = 0;
			continue ;
		}
		count++;
		a = a->next;
	}
	return (count);
}

int	ft_cal_mov_a_op(t_list *a, int pass, int op)
{
	int		count;

	count = 0;
	if (a == NULL || ft_lstsize(a) == 1)
		return (count);
	if (op == RA)
		count = ft_cal_ra_cost(a, pass);
	else
	{
		count = ft_cal_rra_cost(a, pass);
		count++;
	}
	return (count);
}
