/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:16:40 by mrhyhorn          #+#    #+#             */
/*   Updated: 2024/03/12 21:52:51 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	ft_move_collect(int x, int y, t_data *data)
{
	ft_put_img(EMPTY0, x, y, data);
	ft_put_img(EMPTY0, data->game->player_x, data->game->player_y, data);
	ft_put_img(PLAYER0, x, y, data);
	data->game->map[y][x] = '0';
	data->game->collect -= 1;
}

void	ft_move(int x, int y, t_data *data)
{
	if (data->game->map[y][x] == '1')
		return ;
	else if (data->game->map[y][x] == 'E' && data->game->collect != 0)
	{
		ft_game_msg(data, 'k');
		return ;
	}
	else if (data->game->map[y][x] == 'E' && data->game->collect == 0)
	{
		ft_game_msg(data, 'e');
		ft_exit(data);
	}
	else if (data->game->map[y][x] == '0')
	{
		ft_put_img(EMPTY0, data->game->player_x, data->game->player_y, data);
		ft_put_img(PLAYER0, x, y, data);
	}
	else if (data->game->map[y][x] == 'C')
		ft_move_collect(x, y, data);
	data->game->player_x = x;
	data->game->player_y = y;
	data->game->moves += 1;
	ft_print_moves(data);
}

int	ft_key(int key, t_data *data)
{
	int	x;
	int	y;

	x = data->game->player_x;
	y = data->game->player_y;
	data->game->map[y][x] = '0';
	if (key == ESC || key == Q)
	{
		ft_game_msg(data, 'q');
		ft_exit(data);
	}
	else if (key == W || key == UP)
		ft_move(x, y - 1, data);
	else if (key == A || key == LEFT)
		ft_move(x - 1, y, data);
	else if (key == S || key == DOWN)
		ft_move(x, y + 1, data);
	else if (key == D || key == RIGHT)
		ft_move(x + 1, y, data);
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
	data->mlx_win = mlx_new_window(data->mlx, win_w * ASSET_SIZE, win_h
			* ASSET_SIZE, "SO_LONG");
	if (data->mlx_win == NULL)
		print_error_free("Error\n", data);
	ft_render(data);
	mlx_key_hook(data->mlx_win, ft_key, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}
