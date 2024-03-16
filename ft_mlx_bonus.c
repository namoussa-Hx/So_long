/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:12:04 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/16 15:48:17 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

int	ft_assign_key(int key, t_data *data)
{
	if (key == W || key == UP)
		data->game->current_key = UP;
	else if (key == A || key == LEFT)
		data->game->current_key = LEFT;
	else if (key == S || key == DOWN)
		data->game->current_key = DOWN;
	else if (key == D || key == RIGHT)
		data->game->current_key = RIGHT;
	else
		return (0);
	return (1);
}

int	ft_key(int key, t_data *data)
{
	t_player	*player;

	ft_print_moves(data);
	if (key == ESC)
	{
		ft_game_msg(data, 'q');
		ft_exit(data);
	}
	if (!ft_assign_key(key, data))
		return (0);
	player = data->player;
	data->new_x = player->pos_x;
	data->new_y = player->pos_y;
	handle_movement(data);
	if (data->game->current_key == LEFT || data->game->current_key == RIGHT)
		left_right_player(data);
	if (data->game->current_key == UP || data->game->current_key == DOWN)
		up_down_player(data);
	return (0);
}

int	handle_key_up(int keycode, t_data *data)
{
	t_player	*player;

	(void)keycode;
	player = data->player;
	player->idx = 0;
	if (data->game->current_key == LEFT)
		player->curr_img = player->left_imgs[6];
	else if (data->game->current_key == RIGHT)
		player->curr_img = player->right_imgs[6];
	else if (data->game->current_key == UP)
		player->curr_img = player->up_imgs[5];
	else if (data->game->current_key == DOWN)
		player->curr_img = player->down_imgs[5];
	if (data->game->player_x < data->game->width)
		ft_put_img(EMPTY, data->game->player_x, data->game->player_y, data);
	if (data->game->player_x >= 0)
		ft_put_img(EMPTY, data->game->player_x, data->game->player_y, data);
	if (data->game->player_y < data->game->height && \
	data->game->map[data->game->player_y + 1][data->game->player_x] == '0')
		ft_put_img(EMPTY, data->game->player_x, data->game->player_y + 1, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, player->curr_img,
		player->pos_x, player->pos_y);
	return (0);
}

void	ft_mlx(t_data *data)
{
	int	win_h;
	int	win_w;

	win_h = data->game->height;
	win_w = data->game->width;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		print_error_free("Error\n", data);
	data->mlx_win = mlx_new_window(data->mlx, win_w * ASSET_SIZ, win_h
			* ASSET_SIZ, "so_long");
	if (data->mlx_win == NULL)
		print_error_free("Error\n", data);
	ft_init_enemies(data);
	set_images(data, data->player);
	ft_render(data);
	mlx_hook(data->mlx_win, 2, 0, ft_key, data);
	mlx_hook(data->mlx_win, 3, 0, handle_key_up, data);
	mlx_loop_hook(data->mlx, ft_animation, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}
