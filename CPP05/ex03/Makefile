# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 10:31:23 by dboire            #+#    #+#              #
#    Updated: 2024/08/02 15:55:38 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

SRC =	Bureaucrat.cpp\
		AForm.cpp\
		main.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		ShrubberyCreationForm.cpp\
		Intern.cpp

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