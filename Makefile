# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 16:46:44 by ckrasniq          #+#    #+#              #
#    Updated: 2025/01/22 16:47:27 by ckrasniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

SRCS			=	pipex.c \
					utils.c \

OBJECTS			= $(SRCS:.c=.o)


COMPILING		= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJECTS)
				ar rcs $(NAME) $(OBJECTS)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJECTS)
				ar rcs $(NAME) $(OBJECTS)

.PHONY:			all clean fclean re
