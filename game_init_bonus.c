/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:40:18 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/05 20:12:29 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	ft_init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
}

void	ft_game_msg(t_data *data, char c)
{
	if (data->game->collect != 0 && c == 'k')
	{
		ft_putstr_fd("Door is closed. Collect all balls : ", 1);
		ft_putnbr_fd(data->game->collect, 1);
		ft_putstr_fd(" \n", 1);
	}
	if (c == 'q')
		ft_putstr_fd("Quit game            \n", 1);
	else if (data->game->collect == 0 && c == 'e')
	{
		ft_putstr_fd("Congrats! You WIN : ", 1);
		ft_putnbr_fd(data->game->moves, 1);
		if (data->game->moves == 1)
			ft_putstr_fd(" move\n", 1);
		else
			ft_putstr_fd(" moves\n", 1);
	}
	else if (c == 'V')
		ft_putstr_fd("you  are dead !\n", 1);
}

void	ft_print_moves(t_data *data)
{
	char	*moves;

	data->game->moves += 1;
	moves = ft_itoa(data->game->moves);
	ft_put_img(INFO, 0, 0, data);
	mlx_string_put(data->mlx, data->mlx_win, 25, 30, 0x545252, moves);
	free(moves);
	moves = NULL;
}
