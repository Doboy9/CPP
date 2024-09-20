/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:10:10 by dboire            #+#    #+#             */
/*   Updated: 2024/09/20 11:10:10 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av)
{
	RPN rpn;
	std::string string(av[1]);
	
	if (ac == 2)
	{
		if(string.find_first_not_of("0123456789/*-+ ") != std::string::npos)
			std::cout << "Error" << std::endl;
		else
			rpn.parsing(string);
	}
	else
		std::cout << "Please enter two arguments" << std::endl;
}