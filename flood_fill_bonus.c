/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:40:05 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/03 19:07:34 by namoussa         ###   ########.fr       */
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
		|| map[y][x] == 'e')
		return ;
	if (map[y][x] == 'C')
		map[y][x] = 'c';
	else if (map[y][x] == '0')
		map[y][x] = 'O';
	else if (map[y][x] == 'E')
		map[y][x] = 'e';
	flood_fill(data, x, y + 1);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x - 1, y);
}

int	check_flood_fill(t_data *data)
{
	int		x;
	int		y;
	int		did_exit;
	char	**map;

	map = data->game->map;
	did_exit = 0;
	y = 0;
	while (y < data->game->height)
	{
		x = -1;
		while (++x < data->game->width)
		{
			if (map[y][x] == 'C')
				return (COLLECT_UNREACHABLE);
			else if (map[y][x] == 'e')
				map[y][x] = (did_exit++, 'E');
			else if (map[y][x] == 'c')
				map[y][x] = 'C';
			else if (map[y][x] == 'O')
				map[y][x] = '0';
		}
		y++;
	}
	return (did_exit == 0);
}
