/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:49:00 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/03 19:08:11 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	ft_push_enemy(t_enemy **first_enemy, t_enemy *new_enemy)
{
	t_enemy	*temp;

	if (*first_enemy == NULL)
		*first_enemy = new_enemy;
	else
	{
		temp = *first_enemy;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_enemy;
	}
}

t_enemy	*ft_new_enemy(int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (new_enemy == NULL)
		return (NULL);
	new_enemy->enemy_x = x;
	new_enemy->enemy_y = y;
	new_enemy->next = NULL;
	return (new_enemy);
}

t_enemy	*ft_init_enemies(t_data *data)
{
	int		x;
	int		y;
	t_enemy	*new_enemy;

	y = 0;
	while (y < data->game->height)
	{
		x = 0;
		while (x < data->game->width)
		{
			if (data->game->map[y][x] == 'V')
			{
				new_enemy = ft_new_enemy(x, y);
				ft_push_enemy(&data->enemy, new_enemy);
				new_enemy = NULL;
			}
			x++;
		}
		y++;
	}
	return (data->enemy);
}
