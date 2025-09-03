# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunlee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/06 17:33:29 by sunlee            #+#    #+#              #
#    Updated: 2025/07/06 17:33:30 by sunlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c -I.

NAME	= libftprintf.a

SRCS = \
	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
	ft_putnbr_unsigned.c ft_puthex.c ft_putptr.c ft_puthex_ulong.c
	
OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re