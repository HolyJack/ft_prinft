# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:37:11 by ejafer            #+#    #+#              #
#    Updated: 2021/11/24 19:37:11 by ejafer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a
TEST	=	test

NAMES	=   ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putnbr_pf.c ft_putunbr_pf.c ft_puthex_lower.c ft_puthex_upper.c ft_puthex_pf.c ft_putpercent_pf.c
SRC		=	$(addprefix source/, ${NAMES})

OBJ		=	$(SRC:.c=.o)
D_FILES =	${SRC:.c=.d}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OPFLAGS	=	-O2

all: ${NAME}

$(NAME): ${OBJ}
			ar rcs ${NAME} $?

${TEST}: ${NAME}
			${CC} ${CFLAGS} ${OPFLAGS} -Iincludes -L. main.c -lftprintf -Llibft -lft

%.o: %.c ${HDR}
			$(CC) $(CFLAGS) ${OPFLAGS} -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
			@rm -f ${OBJ} ${D_FILES}

fclean:	clean
			@rm -f ${TRGT}

re:	fclean all

.PHONY: re fclean clean bonus all