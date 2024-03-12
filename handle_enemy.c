/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:43:16 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/12 19:44:41 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	handle_enemy1(t_data *data, int map_x, int map_y)
{
	if (data->new_y % ASSET_SIZ > 0 && (data->game->map[map_y][map_x] == 'V' || \
	data->game->map[map_y + 1][map_x] == 'V'))
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
	if (data->new_x % ASSET_SIZ > 0 && (data->game->map[map_y][map_x
			+ 1] == 'V'))
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

void	handle_enemy2(t_data *data, int map_x, int map_y)
{
	if (data->new_x % ASSET_SIZ > 0 && data->new_y % ASSET_SIZ > 0
		&& data->game->map[map_y + 1][map_x + 1] == 'V')
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

void	is_enemy(t_player *player, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->new_x / ASSET_SIZ;
	map_y = data->new_y / ASSET_SIZ;
	player->pos_x = data->new_x;
	player->pos_y = data->new_y;
	data->game->player_x = player->pos_x / ASSET_SIZ;
	data->game->player_y = player->pos_y / ASSET_SIZ;
	if (data->game->map[map_y][map_x] == 'V')
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
	if (data->new_x % ASSET_SIZ > 0 || data->new_y % ASSET_SIZ > 0)
	{
		handle_enemy1(data, map_x, map_y);
		handle_enemy2(data, map_x, map_y);
	}
}
