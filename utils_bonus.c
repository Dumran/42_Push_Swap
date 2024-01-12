/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:36 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/12 11:05:00 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

long long	ft_atoi_l(const char *str)
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
