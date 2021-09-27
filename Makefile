# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgurn <pgurn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 20:26:54 by pgurn             #+#    #+#              #
#    Updated: 2021/09/27 23:05:56 by pgurn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

FILES			=	philo_main.c \
					ft_utils.c \
			
SDIR			= srcs/

SRCS			= $(patsubst %.c, ${SDIR}/%.c, $(FILES))

OBJS			= $(SRCS:.c=.o)

CC				= gcc

RM				= rm -f

HEADER			= -I srcs/

HEADER_FILE		= srcs/philosophers.h

CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

.c.o:
				$(CC) ${HEADER} $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) ${HEADER_FILE}
				$(CC) ${HEADER} $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				${RM} ${OBJS}

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re