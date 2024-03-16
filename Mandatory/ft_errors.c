/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:01:46 by mrhyhorn          #+#    #+#             */
/*   Updated: 2024/03/13 13:28:43 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	print_error_free(char *str, t_data *data)
{
	ft_free_map(data);
	free(data->game);
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_display_error(int e, t_data *data)
{
	if (e == INVALID_RECT)
		print_error_free("Error\nMap is not rectangular\n", data);
	else if (e == INVALID_WALLS)
		print_error_free("Error\nInvalid walls\n", data);
	else if (e == INVALID_CHARS)
		print_error_free("Error\nMap has invalid characters\n", data);
	else if (e == PLAYER_ERROR)
		print_error_free("Error\nplayers\n", data);
	else if (e == EXIT_ERROR)
		print_error_free("Error\n exit\n", data);
	else if (e == COLLECT_ERROR)
		print_error_free("Error\nMap has no collectibles\n", data);
	else if (e == EXIT_UNREACHABLE)
		print_error_free("Error\nplayer can't reach exit\n", data);
	else if (e == COLLECT_UNREACHABLE)
		print_error_free("Error\nplayer can't collect all collectibles\n",
			data);
}
