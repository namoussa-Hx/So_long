/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:34:54 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/06 17:46:43 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

int	ft_animation(t_data *data)
{
	ft_collect_animation(data);
	ft_enemy_anim(data);
	return (0);
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
