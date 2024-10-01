/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:58:46 by dboire            #+#    #+#             */
/*   Updated: 2024/10/01 14:29:51 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if(ac >= 2)
	{
		std::string str;
		for(int i = 1; i < ac; ++i)
		{
			str += av[i];
			if(i < ac - 1)
				str += " ";
		}
		if(str.find_first_not_of("0123456789 ") != std::string::npos)
		{
			std::cout << "Error" << std::endl;
			return(1);
		}
		PmergeMe pmergeme;
		pmergeme.parsing(str);
		return(0);
	}
		std::cout << "Error" << std::endl;
}