# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 20:15:28 by ejafer            #+#    #+#              #
#    Updated: 2021/10/18 19:05:30 by ejafer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

HDR		= 	libft.h

SRC		=	ft_atoi.c		ft_bzero.c		ft_calloc.c\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c\
			ft_isdigit.c	ft_isprint.c	ft_itoa.c\
			ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
			ft_memmove.c	ft_memset.c		ft_putchar_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c\
			ft_split.c		ft_strchr.c		ft_strdup.c\
			ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
			ft_strlcpy.c	ft_strlen.c		ft_strmapi.c\
			ft_strncmp.c	ft_strnstr.c	ft_strnstr.c\
			ft_strrchr.c	ft_strtrim.c	ft_substr.c\
			ft_tolower.c	ft_toupper.c	ft_memccpy.c

SRC_B	=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c		ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c	ft_lstclear_bonus.c\
			ft_lstiter_bonus.c		ft_lstmap_bonus.c\
			ft_lstdelone_bonus.c


OBJ		=	$(SRC:.c=.o)
OBJ_B	=	$(SRC_B:.c=.o)

D_FILES =	${SRC:.c=.d} ${SRC_B:.c=.d}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OPFLAGS	=	-O2

all: ${NAME}

$(NAME): ${OBJ}
			ar rcs ${NAME} $?

bonus: 
			@make OBJ="${OBJ_B}" all

%.o: %.c ${HDR}
			$(CC) $(CFLAGS) ${OPFLAGS} -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
			@rm -f ${OBJ} ${OBJ_B} $(D_FILES)

fclean:	clean
			@rm -f ${TRGT}

re:	fclean all

.PHONY: re fclean clean bonus all