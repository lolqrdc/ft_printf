# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 11:10:13 by loribeir          #+#    #+#              #
#    Updated: 2024/11/24 14:39:27 by loribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_print_char.c\
		ft_print_decimal.c\
		ft_print_hex.c\
		ft_print_ptr.c\
		ft_print_sign.c\
		ft_print_str.c\
		ft_printf.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re