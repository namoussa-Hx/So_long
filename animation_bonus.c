/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:34:54 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/13 00:01:13 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

int	ft_animation(t_data *data)
{
	ft_collect_animation(data);
	ft_enemy_anim(data);
	return (0);
}

void	handle_conditions(t_data *data, int enemy_x, int enemy_y)
{
	int			map_x;
	int			map_y;
	t_player	*player;

	player = data->player;
	data->new_x = player->pos_x;
	data->new_y = player->pos_y;
	map_x = data->new_x / ASSET_SIZ;
	map_y = data->new_y / ASSET_SIZ;
	if (data->new_y % ASSET_SIZ
		&& data->game->map[enemy_y][enemy_x] == data->game->map[map_y
		+ 1][map_x])
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

void	ft_put_img_if_valid(char *img, int x, int y, t_data *data)
{
	if (x >= 0 && x < data->game->width && y >= 0 && y < data->game->height
		&& data->game->map[y][x] == '0')
		ft_put_img(img, x, y, data);
}

void	ft_update_player_position(t_player *player, t_data *data)
{
	int	px;
	int	py;

	ft_put_img(EMPTY, data->game->player_x, data->game->player_y, data);
	px = data->game->player_x;
	py = data->game->player_y;
	ft_put_img_if_valid(EMPTY, px + 1, py, data);
	ft_put_img_if_valid(EMPTY, px - 1, py, data);
	ft_put_img_if_valid(EMPTY, px, py + 1, data);
	ft_put_img_if_valid(EMPTY, px, py - 1, data);
	ft_put_img_if_valid(EMPTY, px + 1, py - 1, data);
	ft_put_img_if_valid(EMPTY, px + 1, py + 1, data);
	ft_put_img_if_valid(EMPTY, px - 1, py - 1, data);
	ft_put_img_if_valid(EMPTY, px - 1, py + 1, data);
	data->game->player_x = player->pos_x / ASSET_SIZ;
	data->game->player_y = player->pos_y / ASSET_SIZ;
	mlx_put_image_to_window(data->mlx, data->mlx_win, player->curr_img,
		player->pos_x, player->pos_y);
}
