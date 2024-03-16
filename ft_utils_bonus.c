/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:36:19 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/13 19:47:43 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

int	ft_strlen_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	return (i);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->game->height)
	{
		free(data->game->map[i]);
		i++;
	}
	free(data->game->map);
	data->game->map = NULL;
}

void	ft_delete_list(t_enemy **head)
{
	t_enemy	*next;

	if (*head != NULL)
	{
		while (*head != NULL)
		{
			next = (*head)->next;
			free(*head);
			*head = NULL;
			*head = next;
		}
	}
	free(*head);
	*head = NULL;
}

int	ft_exit(t_data *data)
{
	ft_free_map(data);
	if (data->enemy != NULL)
		ft_delete_list(&data->enemy);
	free(data->game);
	free(data->player);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
}
