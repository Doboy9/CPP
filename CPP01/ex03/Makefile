# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 14:11:47 by dboire            #+#    #+#              #
#    Updated: 2024/06/17 13:20:01 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = assault

SRC =	main.cpp\
		Weapon.cpp\
		HumanA.cpp\
		HumanB.cpp\

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