# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npillet <npillet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 13:00:47 by npillet           #+#    #+#              #
#    Updated: 2026/06/26 21:48:52 by npillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC = ft_printf.c \
		ft_checkformat.c \
		ft_putchar.c \
		ft_lennb.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printdec.c \
		ft_printundec.c \
		ft_printlowhex.c \
		ft_printuphex.c \
		ft_printptr.c


OBJ_PATH = obj/
SRC_PATH = src/

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRCS))

INC = -I include

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

.PHONY: all clean fclean re libft

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all
	make -C $(LIBFT_PATH) bonus

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
