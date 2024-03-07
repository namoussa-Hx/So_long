/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:31:45 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/03 19:07:25 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	ft_enemy_y(int y, t_enemy *temp, t_data *data)
{
	if (data->game->map[y][temp->enemy_x] == '0')
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = '0';
		data->game->map[y][temp->enemy_x] = 'V';
		ft_put_img(EMPTY, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(ENEMY1, temp->enemy_x, y, data);
	}
	temp->enemy_y = y;
	if (data->game->map[temp->enemy_y][temp->enemy_x] == \
	data->game->map[data->game->player_y][data->game->player_x])
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

void	ft_enemy_x(int x, t_enemy *temp, t_data *data)
{
	if (data->game->map[temp->enemy_y][x] == '0')
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = '0';
		data->game->map[temp->enemy_y][x] = 'V';
		ft_put_img(EMPTY, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(ENEMY1, x, temp->enemy_y, data);
	}
	temp->enemy_x = x;
	if (data->game->map[temp->enemy_y][temp->enemy_x] == \
	data->game->map[data->game->player_y][data->game->player_x])
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

void	ft_enemy_anim(t_data *data)
{
	static int	i;
	int			flag;
	int			limit;
	t_enemy		*temp;

	temp = data->enemy;
	limit = 6000;
	i += 1;
	while (temp)
	{
		ft_check_enemy_dir(temp, data, &flag);
		if (flag == DOWN && i == limit)
			ft_enemy_y(temp->enemy_y + 1, temp, data);
		if (flag == UP && i == limit)
			ft_enemy_y(temp->enemy_y - 1, temp, data);
		if (flag == RIGHT && i == limit)
			ft_enemy_x(temp->enemy_x + 1, temp, data);
		if (flag == LEFT && i == limit)
			ft_enemy_x(temp->enemy_x - 1, temp, data);
		temp = temp->next;
	}
	if (i > limit)
		i = 0;
}
