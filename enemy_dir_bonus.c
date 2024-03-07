/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_dir_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:40:05 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/07 19:32:53 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	ft_up_down(t_enemy *temp, t_data *data, int *flag)
{
	int		pos_x;
	int		pos_y;
	int		mid_h;
	int		mid_w;

	mid_h = data->game->height / 2;
	mid_w = data->game->width / 2;
	pos_y = data->game->player_y;
	pos_x = data->game->player_x;
	if (data->game->map[temp->enemy_y + 1][temp->enemy_x] == '0' \
		&& (pos_y > mid_h || temp->enemy_y <= pos_y))
		*flag = DOWN;
	else if (data->game->map[temp->enemy_y - 1][temp->enemy_x] == '0' \
		&& (pos_y <= mid_h || temp->enemy_y > pos_y))
		*flag = UP;
}

void	ft_left_right(t_enemy *temp, t_data *data, int *flag)
{
	int		pos_x;
	int		pos_y;
	int		mid_h;
	int		mid_w;

	mid_h = data->game->height / 2;
	mid_w = data->game->width / 2;
	pos_y = data->game->player_y;
	pos_x = data->game->player_x;
	if (data->game->map[temp->enemy_y][temp->enemy_x - 1] == '0' \
		&& (pos_x < mid_w || temp->enemy_x > pos_x))
		*flag = LEFT;
	else if (data->game->map[temp->enemy_y][temp->enemy_x + 1] == '0' \
		&& (pos_x >= mid_w || temp->enemy_x < pos_x))
		*flag = RIGHT;
}

void	ft_check_enemy_dir(t_enemy *temp, t_data *data, int *flag)
{
	*flag = 0;
	ft_up_down(temp, data, flag);
	ft_left_right(temp, data, flag);
}
