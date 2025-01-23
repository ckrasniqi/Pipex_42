# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 16:46:44 by ckrasniq          #+#    #+#              #
#    Updated: 2025/01/22 16:51:22 by ckrasniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MAKE_LIB 	= ar -rcs

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
SRC 		=	pipex.c \
				utils.c \

OBJ 		= 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
