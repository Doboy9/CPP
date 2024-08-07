/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:44:53 by dboire            #+#    #+#             */
/*   Updated: 2024/08/06 13:59:41 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int ac, char **av) 
{
	if(ac == 2)
	{
		std::string numStr = av[1];

		ScalarConverter::convert(numStr);
		return 0;
	}
}