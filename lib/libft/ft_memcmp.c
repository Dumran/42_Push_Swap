/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:17:19 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:17:20 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (--n)
	{
		if (*ps1 != *ps2)
			return ((unsigned char) *ps1 - (unsigned char) *ps2);
		ps1++;
		ps2++;
	}
	return ((unsigned char) *ps1 - (unsigned char) *ps2);
}
