/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:18:44 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:18:45 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	size_t	i;

	buf = ft_strdup(s);
	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		buf[i] = f(i, buf[i]);
		i++;
	}
	return (buf);
}
