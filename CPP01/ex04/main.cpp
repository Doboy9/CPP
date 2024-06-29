/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:54:11 by dboire            #+#    #+#             */
/*   Updated: 2024/06/29 17:43:31 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main (int ac, char **av)
{
	(void)av;
	std::string str;
	
	if(ac != 4)
		std::cout << "Please enter a filename and two strings" << std::endl;
	else
	{
		std::ifstream infile;
		infile.open(av[1]);
		if(!infile)
		{
			std::cerr << "Error opening the file" << std::endl;
			return (1);
		}
		std::string line;
		while(std::getline(infile, line))
		{
			str += line;
			line = "";
		}
		if(str.find(av[2] != std::string::npos))
			
		std::cout << str << std::endl;
		infile.close();
	}
	return (0);
}