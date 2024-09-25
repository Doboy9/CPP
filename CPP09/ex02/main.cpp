/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:58:46 by dboire            #+#    #+#             */
/*   Updated: 2024/09/24 14:17:42 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		std::string str(av[1]);
		if(str.find_first_not_of("0123456789 ") == std::string::npos)
		{
			PmergeMe pmergeme;
			pmergeme.parsing(str);
			return(0);
		}
	}
		std::cout << "Error" << std::endl;
}