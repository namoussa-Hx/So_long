/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:37:17 by mrhyhorn          #+#    #+#             */
/*   Updated: 2024/03/05 19:25:28 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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
}

void	ft_print_moves(t_data *data)
{
	ft_putstr_fd("You made ", 1);
	ft_putnbr_fd(data->game->moves, 1);
	if (data->game->moves == 1)
		ft_putstr_fd(" move\r", 1);
	else
		ft_putstr_fd(" moves\r", 1);
}
