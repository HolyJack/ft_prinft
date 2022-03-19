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
INC_DIR		= 	include/

LIBFT		=	libft/libft.a

SRC_NAMES	=	ft_printf 		ft_format_str	ft_format_int\
				ft_format_hex	ft_add_width	ft_add_precision_nbr\
				ft_unbr_to_base

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAMES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAMES)))
D_FILES		=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_NAMES)))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3

MD		=	mkdir -p
RM		=	rm -f
AR		=	ar rcs

all: $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)
			cp $(LIBFT) .
			mv  libft.a $(NAME)

$(NAME): $(OBJ) | $(LIBFT)
			$(AR) $(NAME) ${OBJ}

$(OBJ_DIR):
			${MD} $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -I$(INC_DIR) -o $@ -MD

include $(wildcard $(D_FILES))

clean:
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(RM) $(OBJ) $(D_FILES)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: re fclean clean bonus all
