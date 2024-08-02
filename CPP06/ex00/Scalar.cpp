/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:29 by dboire            #+#    #+#             */
/*   Updated: 2024/08/02 14:49:29 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

void ScalarConverter::convert(const std::string &arg) 
{
	int num = std::atoi(arg.c_str());
    char ch = static_cast<char>(num);

	std::cout << num << std::endl << ch << std::endl;
}