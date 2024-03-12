/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:44:41 by mrhyhorn          #+#    #+#             */
/*   Updated: 2024/03/11 21:24:35 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	ft_validate_file_ext(char *file)
{
	char	*dot;

	dot = NULL;
	dot = ft_strchr(file, '.');
	if (dot == NULL)
		return (0);
	if ((ft_strcmp(".ber", dot)) == 0)
		return (1);
	return (0);
}

void	ft_height(t_data *data, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Error\nFile openning\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game->height += 1;
		free(line);
		line = NULL;
	}
	close(fd);
}

void	ft_map_2d(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		h;

	line = NULL;
	h = data->game->height;
	data->game->map = (char **)malloc(sizeof(char *) * (h + 1));
	if (data->game->map == NULL)
		print_error("Error\nMemory allocation failed\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Error\nFile openning\n");
	h = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game->map[h] = ft_strdup(line);
		h++;
		free(line);
		line = NULL;
	}
	data->game->map[h] = 0;
	close(fd);
}

int	ft_read_map(t_data *data, char *file)
{
	int	out;

	if (!(ft_validate_file_ext(file)))
		print_error("Error\nInvalid file\n");
	ft_height(data, file);
	if (data->game->height == 0)
		print_error("Error\nInvalid file\n");
	ft_map_2d(data, file);
	out = ft_validate_map(data);
	if (out > 0)
		ft_display_error(out, data);
	return (0);
}
