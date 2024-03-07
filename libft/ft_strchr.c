/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:48:29 by namoussa          #+#    #+#             */
/*   Updated: 2023/11/17 12:38:15 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	c1;
	int		l;

	c1 = (char )c;
	ptr = (char *)s;
	l = ft_strlen(ptr);
	i = 0;
	if (c1 == '\0')
		return (&ptr[l]);
	while (ptr[i])
	{
		if (ptr[i] == c1)
		{
			return (ptr + i);
		}
		i++;
	}
	return (0);
}
