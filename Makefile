# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 20:26:54 by pgurn             #+#    #+#              #
#    Updated: 2021/09/05 20:04:10 by pgurn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCDIR	= srcs/

FILES	=	philo_main.c \
			ft_parser.c \
			ft_utils.c \
			initialize.c \
			messages.c \
			simulation.c \=

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I -D

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $(OBJS) -o $(NAME)

all:		${NAME}
			@echo "\\n\033[32;1m 	PHILOSOPHERS COMPLETE \033[0m \\n"

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:		colour
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
