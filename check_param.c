/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:14:17 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/12 11:04:15 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoi_l(const char *str)
{
	size_t		i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (sign * num);
}

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
		if (num == 0 && ft_strncmp(av[i], "0", ft_strlen(av[i])) != 0)
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

	if (!stack || !stack->next)
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
