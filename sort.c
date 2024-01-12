/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:12:42 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:12:44 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstsort(t_list *list)
{
	t_list	*tmp;
	void	*val;

	tmp = list;
	while (tmp->next)
	{
		if (*((int *)(tmp->content)) > *((int *)(tmp->next->content)))
		{
			val = tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = val;
			tmp = list;
		}
		else
			tmp = tmp->next;
	}
}

static void	ft_lstdel_content(void *content)
{
	free(content);
	content = NULL;
}

static void	*ft_lstnew_content(int *content)
{
	int	*new;

	if (!content)
		return (NULL);
	new = (int *) malloc(sizeof(int));
	if (!new)
		return (NULL);
	*new = *content;
	return ((void *) new);
}

static t_list	*ft_lstcopy(t_list *stack)
{
	t_list	*new;
	t_list	*tmp;
	void	*tc;

	new = NULL;
	while (stack)
	{
		tc = ft_lstnew_content((int *) stack->content);
		if (!tc)
		{
			ft_lstclear(&new, ft_lstdel_content);
			return (NULL);
		}
		tmp = ft_lstnew(tc);
		if (!tmp)
		{
			ft_lstclear(&new, ft_lstdel_content);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		stack = stack->next;
	}
	return (new);
}

int	ft_get_pivot(t_list *a)
{
	t_list	*tmp;
	t_list	*iter;
	int		size;
	int		i;
	int		pivot;

	tmp = ft_lstcopy(a);
	if (!tmp)
		ft_exiterr(11, a);
	ft_lstsort(tmp);
	size = ft_lstsize(tmp);
	i = 1;
	iter = tmp;
	while (iter)
	{
		if (i++ == size / 2 + 1)
		{
			pivot = *((int *) iter->content);
			ft_lstclear(&tmp, ft_lstdel_content);
			return (pivot);
		}
		iter = iter->next;
	}
	ft_lstclear(&tmp, ft_lstdel_content);
	return (ft_exiterr(12, a), EXIT_FAILURE);
}
