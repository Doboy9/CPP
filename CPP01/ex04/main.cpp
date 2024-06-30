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
	std::size_t found;
	std::string str;
	std::string arg1 = av[2];
	
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
		
		found = str.find(av[2]);
		
		while (found != std::string::npos)
		{
			str.erase(found, arg1.length());
			str.insert(found, av[3]);
			found = str.find(av[2], found + arg1.length());
		}
		
		infile.close();
		
		std::string replace = av[1];
		std::ofstream outfile;
		
		replace += ".replace";
		outfile.open(replace.c_str());
		outfile << str;
		outfile.close();
	}
	return (0);
}