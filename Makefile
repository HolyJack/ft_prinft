# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:37:11 by ejafer            #+#    #+#              #
#    Updated: 2022/01/10 21:47:21 by ejafer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libftprintf.a

LIBFT_DIR	=	libft/
SRC_DIR		=	src/
OBJ_DIR		=	obj/

LIBFT		=	libft/libft.a

HDR			=	include/ft_printf.h
LIBFT_HDR	=	libft/libft.h


SRC_NAMES	=	ft_printf ft_putchar_pf ft_putstr_pf \
				ft_putnbr_pf ft_putunbr_pf ft_puthex_lower \
				ft_puthex_upper ft_puthex_pf ft_putpercent_pf

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAMES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAMES)))
D_FILES		=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_NAMES)))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
OPFLAGS		=	-O2

MD		=	mkdir -p
RM		=	rm -f
AR		=	ar rcs

all: $(NAME) ${LIBFT}

$(NAME): $(OBJ) $(LIBFT)
			@cp $(LIBFT) .
			@mv libft.a $(NAME)
			$(AR) $(NAME) ${OBJ}

$(LIBFT): $(LIBFT_HDR) $(LIBFT_DIR)*.c
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	@${MD} $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OPFLAGS) -c $< -o $@	-MD

include $(wildcard $(D_FILES))

clean:
			@$(MAKE) -C $(LIBFT_DIR) $(MAKECMDGOALS)
			@$(RM) $(OBJ) $(D_FILES)

fclean:	clean
			@$(RM) $(NAME)

re:	fclean all

.PHONY: re fclean clean bonus all
