/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:37:45 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/12 13:13:48 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	handle_movement(t_data *data)
{
	if (data->game->current_key == LEFT)
		data->new_x -= PLAYER_SPEED;
	else if (data->game->current_key == RIGHT)
		data->new_x += PLAYER_SPEED;
	else if (data->game->current_key == UP)
		data->new_y -= PLAYER_SPEED;
	else if (data->game->current_key == DOWN)
		data->new_y += PLAYER_SPEED;
}

int	exit_with_collect(t_data *data, int map_x, int map_y)
{
	if ((data->new_y % ASSET_SIZ > 0 && (data->game->map[map_y][map_x] == 'E' \
	|| data->game->map[map_y + 1][map_x] == 'E')) && (data->game->collect != 0))
	{
		ft_game_msg(data, 'k');
		return (-1);
	}
	if ((data->new_x % ASSET_SIZ > 0 && (data->game->map[map_y][map_x] == 'E' \
	|| data->game->map[map_y][map_x + 1] == 'E')) && (data->game->collect != 0))
	{
		ft_game_msg(data, 'k');
		return (-1);
	}
	if ((data->new_x % ASSET_SIZ > 0 && data->new_y % ASSET_SIZ > 0 && \
	data->game->map[map_y + 1][map_x + 1] == 'E') && (data->game->collect != 0))
	{
		ft_game_msg(data, 'k');
		return (-1);
	}
	if (data->game->map[map_y][map_x] == 'E' && data->game->collect != 0)
	{
		ft_game_msg(data, 'k');
		return (-1);
	}
	return (0);
}

void	exit_without_collect(t_data *data, int map_x, int map_y)
{
	if (data->game->map[map_y][map_x] == 'E' && data->game->collect == 0)
	{
		ft_game_msg(data, 'e');
		ft_exit(data);
	}
	if ((data->new_y % ASSET_SIZ > 0 && (data->game->map[map_y][map_x] == 'E' \
	|| data->game->map[map_y + 1][map_x] == 'E')) && (data->game->collect == 0))
	{
		ft_game_msg(data, 'e');
		ft_exit(data);
	}
	if ((data->new_x % ASSET_SIZ > 0 && (data->game->map[map_y][map_x] == 'E' \
	|| data->game->map[map_y][map_x + 1] == 'E')) && (data->game->collect == 0))
	{
		ft_game_msg(data, 'e');
		ft_exit(data);
	}
	if ((data->new_x % ASSET_SIZ > 0 && data->new_y % ASSET_SIZ > 0 && \
	data->game->map[map_y + 1][map_x + 1] == 'E') && (data->game->collect == 0))
	{
		ft_game_msg(data, 'e');
		ft_exit(data);
	}
}
