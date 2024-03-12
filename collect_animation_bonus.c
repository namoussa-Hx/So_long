/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_animation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:43:50 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/12 17:24:22 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	ft_ball(int i, int w, int h, t_data *data)
{
	if (i == 0)
		ft_put_img(BALL0, w, h, data);
	else if (i == 2500)
		ft_put_img(BALL1, w, h, data);
	else if (i == 4500)
		ft_put_img(BALL2, w, h, data);
	else if (i == 6500)
		ft_put_img(BALL3, w, h, data);
	else if (i == 8500)
		ft_put_img(BALL4, w, h, data);
}

void	ft_anim(t_data *data)
{
	static int	i;
	int			h;
	int			w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			if (data->game->map[h][w] == 'C')
				ft_ball(i, w, h, data);
			w += 1;
		}
		h += 1;
	}
	i++;
	if (i > 12000)
		i = 0;
}

void	ft_collect_animation(t_data *data)
{
	if (data->game->collect > 0)
		ft_anim(data);
}
