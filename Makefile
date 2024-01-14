NAME		= push_swap
BONUS		= checker

SRCS		= main.c check_param.c utils.c sort.c \
	ops_push.c ops_swap.c ops_rotate.c ops_reverse.c \
	animus_a.c animus_b.c case.c \
	op.c op_utils.c op_cost.c
BONUS_SRCS	= checker_bonus.c check_param_bonus.c utils_bonus.c \
	op_bonus.c ops_push_bonus.c ops_swap_bonus.c ops_rotate_bonus.c \
	ops_reverse_bonus.c

LIBFT_DIR	= lib/libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -g

$(NAME): $(LIBFT) $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_DIR)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_SRCS)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -L$(LIBFT_DIR) -lft -o $(BONUS)

clean:
	make -s -C $(LIBFT_DIR) clean

fclean: clean
	make -s -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
