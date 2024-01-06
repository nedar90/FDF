# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:53:44 by nrajabia          #+#    #+#              #
#    Updated: 2023/04/03 10:53:47 by nrajabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBMLX	:= ./MLX42
PRINTF	:= ./ft_printf

HEADERS	:= -I ./$(PRINTF) -I ./include -I $(LIBMLX)/include/MLX42
LIBP	:= $(PRINTF)/libftprintf.a
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./source -iname "*.c")\
			$(shell find ./libft -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

libmlx:
	@if ! [ -d "./MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
		cd $(LIBMLX); cmake -B build ; cmake --build build -j4; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): libmlx $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(LIBP) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf ./MLX42

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx