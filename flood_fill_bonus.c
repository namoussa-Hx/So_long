/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:40:05 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/16 15:47:50 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	flood_fill(t_data *data, int x, int y)
{
	char	**map;

	map = data->game->map;
	if (x > data->game->width || x < 0 || y > data->game->height || y < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'O' || map[y][x] == 'c'
		|| map[y][x] == 'E' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		map[y][x] = 'c';
	else if (map[y][x] == '0')
		map[y][x] = 'O';
	flood_fill(data, x, y + 1);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x - 1, y);
}

void	flood_fill2(t_data *data, int x, int y)
{
	char	**map;

	map = data->game->map;
	if (x > data->game->width || x < 0 || y > data->game->height || y < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 's' || map[y][x] == 'y'
		|| map[y][x] == 'c' || map[y][x] == 'V')
		return ;
	else if (map[y][x] == 'P')
		map[y][x] = 'y';
	else if (map[y][x] == '0')
		map[y][x] = 's';
	else if (map[y][x] == 'C')
		map[y][x] = 'c';
	flood_fill2(data, x, y + 1);
	flood_fill2(data, x + 1, y);
	flood_fill2(data, x, y - 1);
	flood_fill2(data, x - 1, y);
}

int	check_flood_fill(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	map = data->game->map;
	y = 0;
	while (y < data->game->height)
	{
		x = -1;
		while (++x < data->game->width)
		{
			if (map[y][x] == 'C')
				return (COLLECT_UNREACHABLE);
			else if (map[y][x] == 'c')
				map[y][x] = 'C';
			else if (map[y][x] == 'O')
				map[y][x] = '0';
		}
		y++;
	}
	flood_fill2(data, data->game->exit_x, data->game->exit_y);
	return (check_flood_fill2(data));
}

int	check_flood_fill2(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	map = data->game->map;
	y = 0;
	while (y < data->game->height)
	{
		x = -1;
		while (++x < data->game->width)
		{
			if (map[y][x] == 'P')
				return (EXIT_UNREACHABLE);
			else if (map[y][x] == 'y')
				map[y][x] = 'P';
			else if (map[y][x] == 's')
				map[y][x] = '0';
			else if (map[y][x] == 'c')
				map[y][x] = 'C';
		}
		y++;
	}
	return (0);
}
