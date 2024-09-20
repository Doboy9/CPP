/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:10:14 by dboire            #+#    #+#             */
/*   Updated: 2024/09/20 11:10:14 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){};
RPN::~RPN(){};

void RPN::parsing(std::string av)
{
	for(std::string::size_type i = 0; i < av.size(); i += 2)
	{
		if(std::isdigit(av[i]) && av[i + 1] == ' ')
			_number_list.push_back((av[i] - '0'));
		else if (std::string("/*-+").find(av[i]) != std::string::npos)
			_operator_list.push_back(av[i]);
		else
		{
		 	std::cout << "Error" << std::endl;
			return ;
		}
	}
	if(_number_list.size() - _operator_list.size() != 1)
		std::cout << "Error" << std::endl;
	else
		exec();
}

void RPN::exec()
{
	std::list<int>::iterator num_it = _number_list.begin();
    int total = *num_it;
    ++num_it;

	std::list<char>::iterator op_it = _operator_list.begin();
	while (num_it != _number_list.end() && op_it != _operator_list.end())
	{
		int number = *num_it;
        char op = *op_it;

        switch (op)
        {
            case '+':
                total += number;
                break;
            case '-':
                total -= number;
                break;
            case '*':
                total *= number;
                break;
            case '/':
                if (number == 0)
                {
                    std::cout << "Error: Division by zero" << std::endl;
                    return;
                }
                total /= number;
                break;
            default:
                std::cout << "Error: Invalid operator '" << op << "'" << std::endl;
                return;
        }
        ++num_it;
        ++op_it;
	}
	std::cout << total << std::endl;
}