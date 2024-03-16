/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:16:45 by mrhyhorn          #+#    #+#             */
/*   Updated: 2024/03/16 15:39:59 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		print_error("Too few arguments.\n");
	else if (ac > 2)
		print_error("Too many arguments.\n");
	ft_bzero(&data, sizeof(t_data));
	data.game = malloc(sizeof(t_game));
	if (data.game == NULL)
		print_error("Error\nMemory malloc");
	ft_init_game(data.game);
	ft_read_map(&data, av[1]);
	ft_mlx(&data);
	return (0);
}
