# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 15:26:43 by bahn              #+#    #+#              #
#    Updated: 2021/02/16 13:05:53 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
INCFLAGS	= -I./includes

AR			= ar crs

RM			= rm -rf

LIB_DIR		= ./libft

SRC_DIR		= ./srcs/
SRC_FILES	= ft_printf_utils.c \
			  ft_int_format.c \
			  ft_char_format.c \
			  ft_tobase_n.c \
			  ft_strchr_set.c			
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES)) \
			  ./ft_printf.c

OBJ_DIR		= ./
OBJS		= $(SRCS:.c=.o)

.c.o		: $(SRCS)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME) 	: $(OBJS)
	$(MAKE) all -C $(LIB_DIR)
	$(MAKE) bonus -C $(LIB_DIR)
	cp $(LIB_DIR)/libft.a $@
	$(AR) $@ $^

all			: $(NAME)

clean		:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJS)
fclean		:
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
