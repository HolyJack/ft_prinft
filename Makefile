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

HDR		=	./includes/ft_printf.h
LFT		=	./libft/libft.a
LFTDIR	=	./libft/
LFTHDR	=	./libft/libft.h

NAMES	=   ft_printf.c ft_putchar_pf.c ft_putstr_pf.c \
			ft_putnbr_pf.c ft_putunbr_pf.c ft_puthex_lower.c \
			ft_puthex_upper.c ft_puthex_pf.c ft_putpercent_pf.c

SRC		=	$(addprefix source/, ${NAMES})

OBJ		=	$(SRC:.c=.o)
D_FILES =	${SRC:.c=.d}

CC		=	cc
CFLAGS	=	-Wall -Wextra
OPFLAGS	=	-O2

all: ${NAME}

$(NAME): ${OBJ} ${LFT}
			cp ${LFT} .
			mv libft.a ${NAME}
			ar rcs ${NAME} ${OBJ}

${LFT}:	${LFTHDR}
			${MAKE} -C ${LFTDIR} $(MAKECMDGOALS)
%.o: %.c ${HDR}
			$(CC) $(CFLAGS) ${OPFLAGS} -c $< -o $@

include $(wildcard $(D_FILES))

clean:
			${MAKE}	-C ${LFTDIR} $(MAKECMDGOALS)
			@rm -f ${OBJ} ${D_FILES}

fclean:	clean
			@rm -f ${NAME}

re:	fclean all

.PHONY: re fclean clean bonus all
