/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:07:47 by mrhyhorn          #+#    #+#             */
/*   Updated: 2024/03/12 19:47:52 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	ft_put_img(char *img, int x, int y, t_data *data)
{
	int	w;
	int	h;

	x *= ASSET_SIZE;
	y *= ASSET_SIZE;
	data->mlx_img = mlx_xpm_file_to_image(data->mlx, img, &w, &h);
	if (data->mlx_img == NULL)
		print_error_free("Error\nMlx image not found\n", data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x, y);
	mlx_destroy_image(data->mlx, data->mlx_img);
}

void	ft_draw_map(int x, int y, char ch, t_data *data)
{
	if (ch == '0')
		ft_put_img(EMPTY0, x, y, data);
	else if (ch == '1')
		ft_put_img(FLOOR0, x, y, data);
	else if (ch == 'C')
		ft_put_img(BALL0, x, y, data);
	else if (ch == 'P')
	{
		data->game->player_x = x;
		data->game->player_y = y;
		ft_put_img(PLAYER0, x, y, data);
	}
	else if (ch == 'E')
		ft_put_img(EXIT0, x, y, data);
}

void	ft_draw_background(char *img, t_data *data)
{
	int	w;
	int	h;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			ft_put_img(img, w, h, data);
			w++;
		}
		h++;
	}
}

void	ft_render(t_data *data)
{
	int		x;
	int		y;
	char	ch;

	mlx_clear_window(data->mlx, data->mlx_win);
	ft_draw_background(EMPTY0, data);
	y = 0;
	while (y < data->game->height)
	{
		x = 0;
		while (x < data->game->width)
		{
			ch = data->game->map[y][x];
			ft_draw_map(x, y, ch, data);
			x++;
		}
		y++;
	}
}
