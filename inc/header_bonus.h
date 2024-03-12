/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:35:51 by namoussa          #+#    #+#             */
/*   Updated: 2024/03/12 19:36:31 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include "../libft/libft.h"
// #include "get_next_line.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

////////ERROS//////////////
# define VALID 0
# define EXIT_UNREACHABLE 1
# define INVALID_RECT 3
# define INVALID_WALLS 4
# define INVALID_CHARS 5
# define PLAYER_ERROR 6
# define EXIT_ERROR 7
# define COLLECT_ERROR 8
# define COLLECT_UNREACHABLE 9

/////////////ASSET_SIZE//////
# define ASSET_SIZ 60

///////////KEYS//////////
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

//////////assets///////////////
# define INFO "assets/info/info.xpm"
# define FLOOR "assets/wall/floor.xpm"
# define PLAYER_UP "assets/up/guko_higher_5.xpm"
# define PLAYER_LEFT "assets/left/guko_left_7.xpm"
# define PLAYER_DOWN "assets/down/guko_lowest_3.xpm"
# define PLAYER "assets/right/guko_right_7.xpm"
# define EXIT "assets/exit/exit.xpm"
# define BALL0 "assets/balls/frame_2.xpm"
# define BALL1 "assets/balls/frame_3.xpm"
# define BALL2 "assets/balls/frame_4.xpm"
# define BALL3 "assets/balls/frame_5.xpm"
# define BALL4 "assets/balls/frame_6.xpm"
# define ENEMY1 "assets/enemy/freezer1.xpm"
# define EMPTY "assets/empty_space/empty.xpm"

/// left///
# define LEFT1 "assets/left/guko_left_1.xpm"
# define LEFT2 "assets/left/guko_left_2.xpm"
# define LEFT3 "assets/left/guko_left_3.xpm"
# define LEFT4 "assets/left/guko_left_4.xpm"
# define LEFT5 "assets/left/guko_left_5.xpm"
# define LEFT6 "assets/left/guko_left_6.xpm"
# define LEFT7 "assets/left/guko_left_7.xpm"
/////right/////
# define RIGHT1 "assets/right/guko_right_1.xpm"
# define RIGHT2 "assets/right/guko_right_2.xpm"
# define RIGHT3 "assets/right/guko_right_3.xpm"
# define RIGHT4 "assets/right/guko_right_4.xpm"
# define RIGHT5 "assets/right/guko_right_5.xpm"
# define RIGHT6 "assets/right/guko_right_6.xpm"
# define RIGHT7 "assets/right/guko_right_7.xpm"
/////up///
# define UP1 "assets/up/guko_higher_1.xpm"
# define UP2 "assets/up/guko_higher_2.xpm"
# define UP3 "assets/up/guko_higher_3.xpm"
# define UP4 "assets/up/guko_higher_4.xpm"
# define UP5 "assets/up/guko_higher_5.xpm"
# define UP6 "assets/up/guko_higher_6.xpm"
/////DOWN////
# define DOWN1 "assets/down/guko_lowest_1.xpm"
# define DOWN2 "assets/down/guko_lowest_2.xpm"
# define DOWN3 "assets/down/guko_lowest_3.xpm"
# define DOWN4 "assets/down/guko_lowest_4.xpm"
# define DOWN5 "assets/down/guko_lowest_5.xpm"
# define DOWN6 "assets/down/guko_lowest_6.xpm"

typedef struct s_enemy
{
	int				enemy_x;
	int				enemy_y;
	void			*enemy_img;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_game
{
	char			**map;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				collect;
	int				moves;
	int				enemy_num;
	int				enemy_x;
	int				enemy_y;
	int				current_key;
}					t_game;

typedef struct s_player
{
	void			*curr_img;
	void			*left_imgs[7];
	void			*right_imgs[7];
	void			*up_imgs[6];
	void			*down_imgs[6];
	int				idx;
	int				pos_x;
	int				pos_y;
}					t_player;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	int				new_x;
	int				new_y;
	t_game			*game;
	t_player		*player;
	t_enemy			*enemy;
}					t_data;

# define PLAYER_SPEED 20

void				is_enemy(t_player *player, t_data *data);
void				handle_movement(t_data *data);
void				handle_conditions(t_data *data, int enemy_x, int enemy_y);
int					is_exit(t_data *data);
int					check_flood_fill2(t_data *data);
void				flood_fill2(t_data *data, int x, int y);
int					handle_collect1(t_data *data, int map_x, int map_y);
int					handle_collect2(t_data *data, int map_x, int map_y);
int					is_collect(t_player *player, t_data *data);
int					ft_read_map(t_data *data, char *file);
t_enemy				*ft_init_enemies(t_data *data);
int					ft_validate_map(t_data *data);
void				flood_fill(t_data *data, int x, int y);
int					check_flood_fill(t_data *data);
void				up_down_player(t_data *data);
void				left_right_player(t_data *data);
void				ft_update_player_position(t_player *player, t_data *data);
void				up_down(t_data *data, t_player *player, int w, int h);
int					ft_validate_walls(t_data *data, int *h, int *w, int len);
void				ft_check_enemy_dir(t_enemy *temp, t_data *data, int *flag);
void				ft_enemy_anim(t_data *data);
void				handle_movement(t_data *data);
void				ft_mlx(t_data *data);
int					is_wall(t_player *player, t_data *data);
void				ft_move(int x, int y, t_data *data);
void				set_images(t_data *data, t_player *player);
int					ft_render(t_data *data);
void				ft_put_img(char *img, int x, int y, t_data *data);
void				ft_free_map(t_data *data);
void				ft_delete_list(t_enemy **head);
int					ft_strlen_nl(char *s);
int					ft_exit(t_data *data);
int					ft_animation(t_data *data);
void				ft_collect_animation(t_data *data);
void				ft_init_game(t_game *game);
void				ft_print_moves(t_data *data);
void				ft_game_msg(t_data *data, char c);
void				ft_map_2d(t_data *data, char *file);
void				ft_height(t_data *data, char *file);
int					print_error(char *str);
int					print_error_free(char *str, t_data *data);
void				ft_display_error(int e, t_data *data);
int					exit_with_collect(t_data *data, int map_x, int map_y);
void				exit_without_collect(t_data *data, int map_x, int map_y);
/*--------get_next_line------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char				*ft_strdup_gnl(char *str, int len);
char				*ft_strjoin_gnl(char *s1, char *s2);
int					check_line(char *temp);
char				*print_line(char **temp);
char				*get_next_line(int fd);
size_t				ft_strlen_gnl(char *s);

#endif
