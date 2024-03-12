/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:45:54 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/12 19:38:23 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

int	handle_collect1(t_data *data, int map_x, int map_y)
{
	if (map_x < 0 || map_x >= data->game->width || map_y < 0
		|| map_y >= data->game->height)
		return (-1);
	if (data->new_y % ASSET_SIZ > 0 && (data->game->map[map_y][map_x] == 'C' || \
	data->game->map[map_y + 1][map_x] == 'C'))
	{
		ft_put_img(EMPTY, map_x, map_y + 1, data);
		data->game->map[map_y + 1][map_x] = '0';
		ft_put_img(EMPTY, data->game->player_x, data->game->player_y, data);
		data->game->collect--;
		return (0);
	}
	if (data->new_x % ASSET_SIZ > 0 && (data->game->map[map_y][map_x
			+ 1] == 'C'))
	{
		ft_put_img(EMPTY, map_x + 1, map_y, data);
		data->game->map[map_y][map_x + 1] = '0';
		ft_put_img(EMPTY, data->game->player_x, data->game->player_y, data);
		data->game->collect--;
		return (0);
	}
	else
		return (0);
}

int	handle_collect2(t_data *data, int map_x, int map_y)
{
	if (data->new_x % ASSET_SIZ > 0 && data->new_y % ASSET_SIZ > 0
		&& data->game->map[map_y + 1][map_x + 1] == 'C')
	{
		ft_put_img(EMPTY, map_x + 1, map_y + 1, data);
		data->game->map[map_y + 1][map_x + 1] = '0';
		ft_put_img(EMPTY, data->game->player_x, data->game->player_y, data);
		data->game->collect--;
		return (0);
	}
	else
		return (0);
}
