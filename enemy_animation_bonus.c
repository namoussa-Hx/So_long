/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:31:45 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/12 19:40:13 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	ft_enemy_y(int y, t_enemy *temp, t_player *player, t_data *data)
{
	int	map_x;
	int	map_y;

	data->new_x = player->pos_x;
	data->new_y = player->pos_y;
	map_x = data->new_x / ASSET_SIZ;
	map_y = data->new_y / ASSET_SIZ;
	if (data->game->map[y][temp->enemy_x] == '0')
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = '0';
		data->game->map[y][temp->enemy_x] = 'V';
		ft_put_img(EMPTY, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(ENEMY1, temp->enemy_x, y, data);
	}
	temp->enemy_y = y;
	if (data->game->map[temp->enemy_y][temp->enemy_x] == \
	data->game->map[map_y][map_x])
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
}

void	ft_enemy_x(int x, t_enemy *temp, t_player *player, t_data *data)
{
	int	map_x;
	int	map_y;

	data->new_x = player->pos_x;
	data->new_y = player->pos_y;
	map_x = data->new_x / ASSET_SIZ;
	map_y = data->new_y / ASSET_SIZ;
	if (data->game->map[temp->enemy_y][x] == '0')
	{
		data->game->map[temp->enemy_y][temp->enemy_x] = '0';
		data->game->map[temp->enemy_y][x] = 'V';
		ft_put_img(EMPTY, temp->enemy_x, temp->enemy_y, data);
		ft_put_img(ENEMY1, x, temp->enemy_y, data);
	}
	temp->enemy_x = x;
	if (data->game->map[temp->enemy_y][temp->enemy_x] == \
	data->game->map[map_y][map_x])
	{
		ft_game_msg(data, 'V');
		ft_exit(data);
	}
	else
		handle_conditions(data, temp->enemy_x, temp->enemy_y);
}

void	ft_enemy_anim(t_data *data)
{
	static int	i;
	int			flag;
	int			limit;
	t_enemy		*temp;
	t_player	*player;

	temp = data->enemy;
	limit = 6000;
	player = data->player;
	i += 1;
	while (temp)
	{
		ft_check_enemy_dir(temp, data, &flag);
		if (flag == DOWN && i == limit)
			ft_enemy_y(temp->enemy_y + 1, temp, player, data);
		if (flag == UP && i == limit)
			ft_enemy_y(temp->enemy_y - 1, temp, player, data);
		if (flag == RIGHT && i == limit)
			ft_enemy_x(temp->enemy_x + 1, temp, player, data);
		if (flag == LEFT && i == limit)
			ft_enemy_x(temp->enemy_x - 1, temp, player, data);
		temp = temp->next;
	}
	if (i > limit)
		i = 0;
}
