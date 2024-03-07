/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:00:25 by namoussa          #+#    #+#             */
/*   Updated: 2023/11/17 18:12:56 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*m;
	int		len;
	long	l;

	l = (long)n;
	len = ft_len(l);
	m = malloc(sizeof(char) * len + 1);
	if (!m)
		return (NULL);
	m[len] = '\0';
	if (l == 0)
		m[0] = '0';
	if (l < 0)
	{
		l = l * -1;
		m[0] = '-';
	}
	while (l)
	{
		m[--len] = (l % 10) + '0';
		l = l / 10;
	}
	return (m);
}
