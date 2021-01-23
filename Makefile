# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 15:26:43 by bahn              #+#    #+#              #
#    Updated: 2021/01/23 17:24:41 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
INCFLAGS	= -I.

AR		= ar crs
RM		= rm -rf

LIB_DIR		= ./libft

SRC_DIR		= ./
SRC_FILES	= ft_printf.c \
		  ft_printf_utils.c \
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		= ./
OBJS		= $(SRCS:.c=.o)

.c.o		: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCFLAGS)

$(NAME) 	: $(OBJS)
	$(MAKE) all -C $(LIB_DIR)
	#$(MAKE) -C $(LIB_DIR) bonus
	cp $(LIB_DIR)/libft.a $@
	$(AR) $@ $^

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
