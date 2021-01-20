# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 15:26:43 by bahn              #+#    #+#              #
#    Updated: 2021/01/19 17:54:53 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
INCFLAGS	= -I ./libft -I ./includes

AR		= ar crs
RM		= rm -rf

LIB_DIR		= ./libft

SRC_DIR		= ./src
SRC_FILES	= ft_printf.c \
		  ft_printf_utils.c
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		= ./obj
OBJ_FILES	= $(SRC_FILES:.c=.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

$(NAME) 	: $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(LIB_DIR) bonus
	cp $(LIB_DIR)/libft.a $@
	$(AR) $@ $^

$(OBJS)		: $(SRCS)
	$(CC) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

all		: $(NAME)

clean		:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean		:
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re		:
	fclean all

.PHONY		: all clean fclean re
