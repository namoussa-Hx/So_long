/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:52:05 by mrhyhorn          #+#    #+#             */
/*   Updated: 2024/03/12 19:46:28 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ASSET_SIZE 60

# define INFO0 "assets/info/info.xpm"
# define FLOOR0 "assets/wall/floor.xpm"
//# define PLAYER_UP "../assets/up/guko_higher_5.xpm"
//# define PLAYER_LEFT "../assets/left/guko_left_7.xpm"
//# define PLAYER_DOWN "../assets/down/guko_lowest_3.xpm"
# define PLAYER0 "assets/right/guko_right_7.xpm"
# define EXIT0 "assets/exit/exit.xpm"
# define BALL0 "assets/balls/frame_2.xpm"
# define EMPTY0 "assets/empty_space/empty.xpm"

# define Q 12
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define VALID 0
# define EXIT_UNREACHABLE 1
# define INVALID_RECT 3
# define INVALID_WALLS 4
# define INVALID_CHARS 5
# define PLAYER_ERROR 6
# define EXIT_ERROR 7
# define COLLECT_ERROR 8
# define COLLECT_UNREACHABLE 9

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit;
	int		moves;
	int		collect;
}			t_game;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	t_game	*game;
}			t_data;

int			ft_read_map(t_data *data, char *file);
int			check_flood_fill2(t_data *data);
void		flood_fill2(t_data *data, int x, int y);
void		flood_fill(t_data *data, int x, int y);
int			check_flood_fill(t_data *data);
int			ft_validate_map(t_data *data);
int			ft_validate_walls(t_data *data, int *h, int *w, int len);
void		ft_mlx(t_data *data);
void		ft_render(t_data *data);
void		ft_put_img(char *img, int x, int y, t_data *data);
void		ft_free_map(t_data *data);
void		ft_init_game(t_game *game);
int			ft_strlen_nl(char *s);
int			ft_exit(t_data *data);
void		ft_height(t_data *data, char *file);
void		ft_print_moves(t_data *data);
void		ft_game_msg(t_data *data, char c);
void		ft_map_2d(t_data *data, char *file);
void		ft_display_error(int e, t_data *data);
int			print_error(char *str);
int			print_error_free(char *str, t_data *data);

/*--------get_next_line------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*ft_strdup_gnl(char *str, int len);
char		*ft_strjoin_gnl(char *s1, char *s2);
int			check_line(char *temp);
char		*print_line(char **temp);
char		*get_next_line(int fd);
size_t		ft_strlen_gnl(char *s);

#endif
