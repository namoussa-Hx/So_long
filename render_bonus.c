/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:23:05 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/06 14:12:26 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	ft_put_img(char *img, int x, int y, t_data *data)
{
	int	w;
	int	h;

	x *= ASSET_SIZ;
	y *= ASSET_SIZ;
	data->mlx_img = mlx_xpm_file_to_image(data->mlx, img, &w, &h);
	if (data->mlx_img == NULL)
		print_error_free("Error\nimage not found\n", data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x, y);
	mlx_destroy_image(data->mlx, data->mlx_img);
}

void	ft_draw_map(int x, int y, char ch, t_data *data)
{
	int	i;

	i = 0;
	if (ch == '0')
		ft_put_img(EMPTY, x, y, data);
	if (ch == '1')
		ft_put_img(FLOOR, x, y, data);
	else if (ch == 'C')
		ft_put_img(BALL0, x, y, data);
	else if (ch == 'P')
	{
		ft_put_img(RIGHT7, x, y, data);
		data->game->map[data->game->player_y][data->game->player_x] = '0';
	}
	else if (ch == 'E')
		ft_put_img(EXIT, x, y, data);
	else if (ch == 'V')
		ft_put_img(ENEMY1, x, y, data);
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

int	ft_render(t_data *data)
{
	int		x;
	int		y;
	char	ch;

	mlx_clear_window(data->mlx, data->mlx_win);
	ft_draw_background(EMPTY, data);
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
	return (0);
}
