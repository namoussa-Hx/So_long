NAME = so_long

#---mandatory part---#
SRCS_M = Mandatory/main.c\
			Mandatory/ft_mlx.c \
			Mandatory/ft_utils.c\
			Mandatory/ft_read_map.c \
			Mandatory/ft_validate_map.c\
			Mandatory/ft_errors.c \
			Mandatory/ft_validate_walls.c\
			Mandatory/ft_render.c \
			Mandatory/get_next_line.c \
			Mandatory/get_next_line_utils.c \
			Mandatory/ft_game_utils.c \
			Mandatory/flood_fill.c

#---bonus part---#
NAME_B = so_long_bonus

SRCS_B = so_long_bonus.c \
       ft_utils_bonus.c \
       validate_map_bonus.c \
       read_map_bonus.c \
       ft_validate_wall_bonus.c \
       ft_error_bonus.c \
       ft_mlx_bonus.c \
       render_bonus.c \
       game_init_bonus.c \
       move_bonus.c \
       animation_bonus.c \
       collect_animation_bonus.c \
       enemy_animation_bonus.c \
       enemy_dir_bonus.c \
       flood_fill_bonus.c \
       get_next_line_bonus.c \
       get_next_line_utils_bonus.c\
       init_enemies_bonus.c\
       utils2_bonus.c\
	   check_collect_bonus.c\
	   handle_enemy.c

MLX =  -Lminilibx -lmlx -framework OpenGL -framework AppKit



RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
YELLOW	=	\033[0;33m

CC = cc
CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -g3

LIBFT_MAKE = make -C libft
MINILIBX_MAKE = make -C minilibx


all: $(NAME)

$(NAME): $(SRCS_M)
	$(LIBFT_MAKE)
	$(MINILIBX_MAKE)
	$(CC) $(CFLAGS) $(SRCS_M) -L libft -lft -Lminilibx $(MLX) -o $(NAME)
	@echo "$(YELLOW)libmlx.a $(GREEN) --> DONE!"
	@echo "$(YELLOW)libft.a $(GREEN) --> DONE!"
	@echo "$(YELLOW)$(NAME)$(GREEN) --> DONE!"

bonus: $(NAME_B)

$(NAME_B): $(SRCS_B)
	$(LIBFT_MAKE)
	$(MINILIBX_MAKE)
	$(CC)  $(CFLAGS) $(SRCS_B) -L libft -lft -Lminilibx $(MLX) -o $(NAME_B)
	@echo "$(YELLOW)libmlx.a $(GREEN) --> DONE!"
	@echo "$(YELLOW)libft.a $(GREEN) --> DONE!"
	@echo "$(YELLOW)$(NAME_B)$(GREEN) --> DONE!"

clean:
	make clean -C libft
	make clean -C minilibx

fclean: clean 
	make fclean -C libft
	rm -f $(NAME)
	rm -f $(NAME_B)
	@echo "$(YELLOW)libft.a $(RED)--> DELETED$(BREAK)"
	@echo "$(YELLOW)$(NAME) $(RED)--> DELETED$(BREAK)"
	@echo "$(YELLOW)$(NAME_B) $(RED)--> DELETED$(BREAK)"

re: fclean all

.PHONY: all bonus clean fclean re
