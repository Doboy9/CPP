/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:29 by dboire            #+#    #+#             */
/*   Updated: 2024/09/29 17:24:28 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

ScalarConverter::~ScalarConverter(){};
ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter& ){};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& ){return *this;}

void ScalarConverter::convert(const std::string &arg) 
{
	if(arg == "nan" || arg == "-inf" || arg == "+inf" || arg == "-inff" || arg == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if(arg == "-inff" || arg == "+inff")
			std::cout << "float: " << arg << std::endl;
		else
			std::cout << "float: " << arg << "f" << std::endl;
		std::cout << "double: " << arg << std::endl;
		return ;
	}
	int i = 0;
	int j = 0;
	int k = 0;
	if(std::isdigit(arg[0]) && arg.length() != 1)
	{
		while(arg[i])
		{
			if(arg[i] == 'f')
				j++;
			if(arg[i] == '.')
				k++;
			if(!std::isdigit(arg[i]) && (j >= 2 || k >= 2))
			{
				std::cout << "Please enter valid parameter" << std::endl;
				return ;
			}
			i++;
		}
	}

	if(!std::isdigit(arg[0]) && arg.length() == 1) // Is a char
	{
		char cchar;
		float fnum = 0.0f;
		double dnum = 0.0;
		int i = 0;

		cchar = arg[0];
		fnum = static_cast<float>(cchar);
		dnum = static_cast<double>(cchar);
		i = static_cast<int>(cchar);

		if (std::isprint(cchar))
			std::cout << "char: " << cchar << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "int: " << i << std::endl 
		<< "float: " << fnum << "f" << std::endl
		<< "double: " << dnum << std::endl;
		return ;
	}
	if(std::isdigit(arg[0]) && arg.find('.') == std::string::npos && arg.find_first_not_of("0123456789") == std::string::npos)
	{
		char *end;
		char cchar;
		float fnum = 0.0f;
		double dnum = 0.0;
		int i = 0;

		dnum = std::strtod(arg.c_str(), &end);
		i = static_cast<int>(dnum);
		cchar = static_cast<char>(dnum);
		fnum = static_cast<float>(dnum);
		if (std::isprint(cchar))
			std::cout << "char: " << cchar << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "int: " << i << std::endl 
		<< "float: " << fnum << "f" << std::endl
		<< "double: " << dnum << std::endl;
		return ;
	}
	if(std::isdigit(arg[0]) && arg.find('.') != std::string::npos && arg[arg.length() - 1] == 'f' && arg.find_first_not_of("0123456789f.") == std::string::npos) // Is a float
	{
		char *end;
		char cchar;
		float fnum = 0.0f;
		double dnum = 0.0;
		int i = 0;

		fnum = std::strtof(arg.c_str(), &end);
		i = static_cast<int>(fnum);
		dnum = static_cast<double>(fnum);
		cchar = static_cast<char>(dnum);
		if (std::isprint(cchar))
			std::cout << "char: " << cchar << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "int: " << i << std::endl 
		<< "float: " << fnum << "f" << std::endl
		<< "double: " << dnum << std::endl;
		return ;
	}
	else if(std::isdigit(arg[0]) && arg.find('.') != std::string::npos && arg.find_first_not_of("0123456789.") == std::string::npos) // Is a double
	{
		char *end;
		char cchar;
		double dnum = 0.0;
		float fnum = 0.0f;

		dnum = std::strtod(arg.c_str(), &end);
		i = static_cast<int>(dnum);
		fnum = static_cast<float>(dnum);
		cchar = static_cast<char>(dnum);
		if (std::isprint(cchar))
			std::cout << "char: " << cchar << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "int: " << i << std::endl 
		<< "float: " << fnum << "f" << std::endl
		<< "double: " << dnum << std::endl;
		return ;
	}
	std::cout << "Wrong parameters" << std::endl;
	return ;
}