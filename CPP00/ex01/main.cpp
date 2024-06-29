/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:46:35 by dboire            #+#    #+#             */
/*   Updated: 2024/06/29 18:20:54 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <cstdlib>

int	only_isspace(std::string in)
{
	for(size_t i = 0; i == in.length(); i++)
	{
		if(std::isspace(in[i]))
			return (0);
	}
	return (1);
}

int main(){
	
	int i = 0;
	Phonebook contact_list;
	std::string in;

	while(1)
	{
		std::cout << "Phonebook > ";
		if (!std::getline(std::cin, in))
 		   return(1);
		if (in == "ADD")
		{
			if (i == 8)
				i = 0;
			contact_list.Add_info(in, i);
			i++;
		}
		else if (in == "SEARCH")
		{
			contact_list.Search();
		}
		else if (in == "EXIT")
		{
			exit(0);
		}
		else
			std::cout << "Please enter ADD / SEARCH / EXIT" << std::endl;
	}
}