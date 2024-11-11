/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:10:14 by dboire            #+#    #+#             */
/*   Updated: 2024/11/11 13:45:00 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};
RPN::~RPN() {};

RPN::RPN(const RPN &other) : _number_list(other._number_list), _operator_list(other._operator_list) {};

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		_number_list = src._number_list;
		_operator_list = src._operator_list;
	}
	return *this;
}

void RPN::parsing(const std::string &av)
{
	std::string token;
	for (std::string::size_type i = 0; i < av.length(); ++i)
	{
		if (av[i] == ' ')
			continue;

		token = av[i];
		if (std::isdigit(av[i]) || std::string("+-*/").find(av[i]) != std::string::npos)
			_tokens.push_back(token);
		else
		{
			std::cout << "Error" << std::endl;
			return;
		}
	}
	exec();
}

void RPN::exec()
{
	std::list<int> stack;
	std::list<std::string>::iterator it;

	for (it = _tokens.begin(); it != _tokens.end(); ++it)
	{
		if (isdigit((*it)[0]))
		{
			std::istringstream iss(*it);
			int value;
			iss >> value;
			stack.push_back(value);
			continue;
		}

		if (stack.size() < 2)
		{
			std::cout << "Error" << std::endl;
			return;
		}

		int b = stack.back();
		stack.pop_back();
		int a = stack.back();
		stack.pop_back();

		switch ((*it)[0])
		{
		case '+':
			stack.push_back(a + b);
			break;
		case '-':
			stack.push_back(a - b);
			break;
		case '*':
			stack.push_back(a * b);
			break;
		case '/':
			if (b == 0)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			stack.push_back(a / b);
			break;
		default:
			std::cout << "Error" << std::endl;
			return;
		}
	}

	if (stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return;
	}

	std::cout << stack.back() << std::endl;
}