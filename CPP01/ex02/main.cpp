/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:45:48 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 13:16:44 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "Memory address of string : " << &string << std::endl
	<< "Value of the string : " << string << std::endl;
	
	std::cout << "Memory address of string : " << stringPTR << std::endl
	<< "Value of the string : " << *stringPTR << std::endl;
	
	std::cout << "Memory address of string : " << &stringREF << std::endl
	<< "Value of the string : " << stringREF << std::endl;
}