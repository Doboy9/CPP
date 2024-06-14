# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 14:11:47 by dboire            #+#    #+#              #
#    Updated: 2024/06/14 14:11:47 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = ex00.cpp\

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM	=	rm -f

OBJS = ${SRC:.cpp=.o}

%.o: %.c
	c++ ${CFLAGS} -c $< -o $@

${NAME} :	${OBJS}
		c++ ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all bonus clean fclean re