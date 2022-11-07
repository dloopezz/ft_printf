# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:59:19 by dlopez-s          #+#    #+#              #
#    Updated: 2022/10/27 10:00:59 by lopezz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c\
		ft_writeparams.c\

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME) : $(OBJS)
	@cd libft ; make
	@cp ${LIBFT} ${NAME}
	@ar rsc $(NAME) $(OBJS) ${LIBFT}

clean:
	@cd libft ; make clean
	@rm -f $(OBJS)

fclean: clean
	@cd libft ; make fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re