/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:40:42 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/03 20:00:01 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > 2147483647)
		return (free(temp), temp = NULL, NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(temp), temp = NULL, NULL);
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
		if (!temp)
			return (free(buffer), NULL);
		if (check_line(temp))
			break ;
	}
	free(buffer);
	return (print_line(&temp));
}
/*int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char	*str;
	int		i = 0;

	while (i < 4)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;

	}
	return (0);
}*/
