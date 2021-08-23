NAME		=	so_long

SRCS_FILES	= 	${shell find ./src -name "*.c"}

# UTILS_FILES	= 	${shell find ./Utils -name "*.c"}

SRCS				= 	$(SRCS_FILES)
OBJS				=	$(patsubst %.c,%.o,$(SRCS))
# SRCS_UTILS_FILES	=	$(UTILS_FILES)
# OBJS_UTILS			=	$(patsubst %.c,%.o,$(SRCS_UTILS_FILES))

LIB_DIR		=	libft
MLX_DIR		=	mlx
INC			=	-I./include -I./libft -I./mlx

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

all:		$(NAME)

%.o:		%.c $(INC)
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make -C $(MLX_DIR)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $(INC) $(LIB_DIR)/libft.a $(OBJS) -o $(NAME)

clean:
			@make clean -C $(MLX_DIR)
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re