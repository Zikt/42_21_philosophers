# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 20:26:54 by pgurn             #+#    #+#              #
#    Updated: 2021/08/25 12:48:02 by pgurn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

FILES	=	philo_main.c \

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD) -D MACOS

FLAGS = -L $(LIB) -lft

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

all:		${NAME}
			@echo "\\n\033[32;1m 	PHILOSOPHERS COMPLETE \033[0m \\n"

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:		colour
			make clean -C $(LIB)
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
