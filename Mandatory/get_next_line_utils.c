/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:42:54 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/03 21:01:31 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	*ft_strdup_gnl(char *str, int len)
{
	char	*array;
	int		i;

	if (!str || !len)
		return (NULL);
	i = -1;
	array = (char *)malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (++i < len)
		array[i] = str[i];
	array[i] = '\0';
	return (array);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;

	i = 0;
	len = ft_strlen_gnl(s2);
	if (!s1)
		return (ft_strdup_gnl(s2, len));
	len = len + ft_strlen_gnl(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (free(s1), NULL);
	len = 0;
	while (s1[i])
		array[len++] = s1[i++];
	i = 0;
	while (s2[i])
		array[len++] = s2[i++];
	array[len] = '\0';
	free(s1);
	return (array);
}

int	check_line(char *temp)
{
	int	i;

	if (!temp)
		return (0);
	i = -1;
	while (temp[++i])
		if (temp[i] == 10)
			return (1);
	return (0);
}

char	*print_line(char **temp)
{
	int		i;
	char	*return_line;
	char	*str;

	if (!*temp)
		return (NULL);
	str = *temp;
	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	return_line = ft_strdup_gnl(str, i);
	if (!return_line)
		return (free(*temp), *temp = NULL, NULL);
	*temp = ft_strdup_gnl(str + i, ft_strlen_gnl(str + i));
	free(str);
	return (return_line);
}
