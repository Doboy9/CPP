# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 15:42:20 by dboire            #+#    #+#              #
#    Updated: 2024/08/10 15:43:03 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Iter

SRC =	main.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

RM	=	rm -f

OBJS = ${SRC:.cpp=.o}

%.o: %.c
	$(CXX) ${CXXFLAGS} -c $< -o $@

${NAME} :	${OBJS}
		$(CXX) ${CXXFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all bonus clean fclean re