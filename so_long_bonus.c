/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:28:44 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/16 15:39:49 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header_bonus.h"

void	*file_to_img(t_data *data, char *img_path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, img_path, w, h);
	if (!img)
		print_error_free("MALLOC ERROR", data);
	return (img);
}

void	set_images(t_data *data, t_player *player)
{
	int	w;
	int	h;

	player->left_imgs[0] = file_to_img(data, LEFT1, &w, &h);
	player->left_imgs[1] = file_to_img(data, LEFT2, &w, &h);
	player->left_imgs[2] = file_to_img(data, LEFT3, &w, &h);
	player->left_imgs[3] = file_to_img(data, LEFT4, &w, &h);
	player->left_imgs[4] = file_to_img(data, LEFT5, &w, &h);
	player->left_imgs[5] = file_to_img(data, LEFT6, &w, &h);
	player->left_imgs[6] = file_to_img(data, LEFT7, &w, &h);
	player->right_imgs[0] = file_to_img(data, RIGHT1, &w, &h);
	player->right_imgs[1] = file_to_img(data, RIGHT2, &w, &h);
	player->right_imgs[2] = file_to_img(data, RIGHT3, &w, &h);
	player->right_imgs[3] = file_to_img(data, RIGHT4, &w, &h);
	player->right_imgs[4] = file_to_img(data, RIGHT5, &w, &h);
	player->right_imgs[5] = file_to_img(data, RIGHT6, &w, &h);
	player->right_imgs[6] = file_to_img(data, RIGHT7, &w, &h);
	up_down(data, player, w, h);
	player->idx = 0;
	player->curr_img = player->right_imgs[0];
}

void	up_down(t_data *data, t_player *player, int w, int h)
{
	player->up_imgs[0] = file_to_img(data, UP1, &w, &h);
	player->up_imgs[1] = file_to_img(data, UP2, &w, &h);
	player->up_imgs[2] = file_to_img(data, UP3, &w, &h);
	player->up_imgs[3] = file_to_img(data, UP4, &w, &h);
	player->up_imgs[4] = file_to_img(data, UP5, &w, &h);
	player->up_imgs[5] = file_to_img(data, UP6, &w, &h);
	player->down_imgs[0] = file_to_img(data, DOWN1, &w, &h);
	player->down_imgs[1] = file_to_img(data, DOWN2, &w, &h);
	player->down_imgs[2] = file_to_img(data, DOWN3, &w, &h);
	player->down_imgs[3] = file_to_img(data, DOWN4, &w, &h);
	player->down_imgs[4] = file_to_img(data, DOWN5, &w, &h);
	player->down_imgs[5] = file_to_img(data, DOWN6, &w, &h);
}

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
	data.player = malloc(sizeof(t_player));
	if (data.game == NULL || !data.player)
		print_error("Error\nMemory malloc");
	ft_bzero(data.player, sizeof(t_player));
	ft_init_game(data.game);
	ft_read_map(&data, av[1]);
	ft_mlx(&data);
	return (0);
}
