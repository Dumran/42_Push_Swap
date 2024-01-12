/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkekli <mehkekli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:18:15 by mehkekli          #+#    #+#             */
/*   Updated: 2024/01/04 15:18:16 by mehkekli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
