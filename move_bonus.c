/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:53:55 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/08 15:09:36 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

int	is_collect(t_player *player, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->new_x / ASSET_SIZ;
	map_y = data->new_y / ASSET_SIZ;
	player->pos_x = data->new_x;
	player->pos_y = data->new_y;
	data->game->player_x = player->pos_x / ASSET_SIZ;
	data->game->player_y = player->pos_y / ASSET_SIZ;
	if (handle_collect1(data, map_x, map_y) == -1)
		return (-1);
	if (handle_collect2(data, map_x, map_y) == -1)
		return (-1);
	return (0);
}

int	is_exit(t_data *data)
{
	int	map_x;
	int	map_y;
	int	result;

	map_x = data->new_x;
	map_y = data->new_y;
	map_x /= ASSET_SIZ;
	map_y /= ASSET_SIZ;
	if (map_x < 0 || map_x >= data->game->width || map_y < 0
		|| map_y >= data->game->height)
		return (-1);
	result = exit_with_collect(data, map_x, map_y);
	if (result != 0)
		return (-1);
	exit_without_collect(data, map_x, map_y);
	return (0);
}

int	is_wall(t_player *player, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->new_x;
	map_y = data->new_y;
	map_x /= ASSET_SIZ;
	map_y /= ASSET_SIZ;
	if (map_x < 0 || map_x >= data->game->width || map_y < 0
		|| map_y >= data->game->height)
		return (-1);
	if (data->new_y % ASSET_SIZ > 0 && (data->game->map[map_y][map_x] == '1' || \
	data->game->map[map_y + 1][map_x] == '1'))
		return (-1);
	if (data->new_x % ASSET_SIZ > 0 && \
	(data->game->map[map_y][map_x + 1] == '1'))
		return (-1);
	if (data->new_x % ASSET_SIZ > 0 && data->new_y % ASSET_SIZ > 0
		&& data->game->map[map_y + 1][map_x + 1] == '1')
		return (-1);
	if (data->game->map[map_y][map_x] == '1')
		return (-1);
	if (is_exit(data) || is_collect(player, data))
		return (-1);
	return (0);
}

void	left_right_player(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_wall(player, data))
		return ;
	is_enemy(player, data);
	ft_print_moves(data);
	if ((data->game->current_key == LEFT && data->new_x < 0)
		|| (data->game->current_key == RIGHT && data->new_x > (data->game->width
				- 1) * ASSET_SIZ))
		return ;
	player->idx = (player->idx + 1) % 6;
	if (data->game->current_key == LEFT)
		player->curr_img = player->left_imgs[player->idx];
	else if (data->game->current_key == RIGHT)
		player->curr_img = player->right_imgs[player->idx];
	player->pos_x = data->new_x;
	player->pos_y = data->new_y;
	ft_update_player_position(player, data);
}

void	up_down_player(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_wall(player, data))
		return ;
	is_enemy(player, data);
	ft_print_moves(data);
	if ((data->game->current_key == UP && data->new_y < 0)
		|| (data->game->current_key == DOWN && data->new_y > (data->game->height
				- 1) * ASSET_SIZ))
		return ;
	player->idx = (player->idx + 1) % 6;
	if (data->game->current_key == UP)
		player->curr_img = player->up_imgs[player->idx];
	else if (data->game->current_key == DOWN)
		player->curr_img = player->down_imgs[player->idx];
	player->pos_x = data->new_x;
	player->pos_y = data->new_y;
	ft_update_player_position(player, data);
}
