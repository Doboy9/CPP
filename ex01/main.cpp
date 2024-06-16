/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:46:35 by dboire            #+#    #+#             */
/*   Updated: 2024/06/14 18:46:35 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>

int	only_isspace(std::string in)
{
	for(int i = 0; i = in.length(); i++)
	{
		if(!std::isspace(in[i]))
			return (0);
	}
	return (1);
}

void	Add_info(std::string in, Phonebook contact_list)
{
	while(1)
	{
		std::cout << "FIRST NAME > ";
		std::getline(std::cin, in);
		if(in.empty() || only_isspace(in) == 1)
		{
			std::cout << "No empty informations" << std::endl;
		}
		else
			break ;
	}
	contact_list.contact.takeFirstName(in);
	std::cout << contact_list.contact.printFirstName() << std::endl;
	std::cout << "LAST NAME > ";
	std::getline(std::cin, in);
	contact_list.contact.takeLastName(in);
	std::cout << contact_list.contact.printLastName() << std::endl;
	std::cout << "NICKNAME > ";
	std::getline(std::cin, in);
	contact_list.contact.takeNickname(in);
	std::cout << contact_list.contact.printNickname() << std::endl;
	std::cout << "PHONE NUMBER > ";
	std::getline(std::cin, in);
	contact_list.contact.takePhoneNumber(in);
	std::cout << contact_list.contact.printPhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET > ";
	std::getline(std::cin, in);
	contact_list.contact.takeDarkestSecret(in);
	std::cout << contact_list.contact.printDarkestSecret() << std::endl;
}

int main( ){
	
	int i = 0;
	Phonebook contact_list[8];
	std::string in;

	while(1)
	{
		std::cout << "Phonebook > ";
		if (!std::getline(std::cin, in))
 		   exit(1);
		if (in == "ADD")
		{
			if (i == 8)
				i = 0;
			Add_info(in, contact_list[i]);	
			i++;
		}
		if (in == "SEARCH")
		{
			std::cout << "search" << std::endl;
		}
		if (in == "EXIT")
		{
			std::cout << "exit" << std::endl;
		}
	}
}