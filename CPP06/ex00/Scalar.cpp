/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:29 by dboire            #+#    #+#             */
/*   Updated: 2024/08/05 19:28:53 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

ScalarConverter::~ScalarConverter(){};
ScalarConverter::ScalarConverter(){};

void ScalarConverter::convert(const std::string &arg) 
{
	if(!std::isdigit(arg[0]) && arg.length() == 1) // Is a char
	{
		char cchar;
		float fnum = 0.0f;
		double dnum = 0.0;

		cchar = arg[0];
		fnum = static_cast<float>(cchar);
		dnum = static_cast<double>(cchar);

		if (std::isprint(cchar))
			std::cout << "char: " << cchar << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "c" << std::endl << "float: " << fnum << " double: " << dnum << std::endl;
	}

	if(std::isdigit(arg[0]) && std::strchr(arg.c_str(), '.') && arg[arg.length() - 1] == 'f') // Is a float
	{
		char *end;
		char cchar;
		float fnum = 0.0f;
		double dnum = 0.0;

		fnum = std::strtof(arg.c_str(), &end);
		dnum = static_cast<double>(fnum);

		cchar = static_cast<char>(dnum);
		if (std::isprint(cchar))
			std::cout << "char: " << cchar << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "f" << std::endl << "float: " << fnum << "f" << " double: " << dnum << std::endl;
	}

	else if(std::isdigit(arg[0]) && std::strchr(arg.c_str(), '.')) // Is a double
	{
		char *end;
		char cchar;
		double dnum = 0.0;
		float fnum = 0.0f;

		dnum = std::strtod(arg.c_str(), &end);
		fnum = static_cast<float>(dnum);
		cchar = static_cast<char>(dnum);
		if (std::isprint(cchar))
			std::cout << "char: " << cchar << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "d" << std::endl << "float: " << fnum << "f" << " double: " << dnum << std::endl;
	}
}