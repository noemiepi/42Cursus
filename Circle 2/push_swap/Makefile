# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npillet <npillet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 09:43:47 by npillet           #+#    #+#              #
#    Updated: 2026/02/16 13:08:47 by npillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

INC = -I$(LIBFT_PATH)/include

SRC =	push_swap.c				\
		parsing.c				\
		cost.c					\
		sort.c					\
		sort/swap.c				\
		sort/push.c				\
		sort/rotate.c			\
		sort/reverse_rotate.c	\
		utils/stack_utils.c		\
		utils/sort_utils.c		\
		utils/cost_utils.c		\
		utils/pushback_utils.c	\
		utils/check.c			\
		utils/error.c

OBJ_PATH = obj/
SRC_PATH = src/

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRCS))

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	rm -f $(NAME)

re: fclean all
