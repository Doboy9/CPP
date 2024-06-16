/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:46:35 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 09:28:33 by dboire           ###   ########.fr       */
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

void	Phonebook::Add_info(std::string in, int i)
{
	while(1)
	{
		std::cout << "FIRST NAME > ";
		if (!std::getline(std::cin, in))
 			exit(1);
		if(in.empty())
			std::cout << "No empty informations" << std::endl;
		else
			break ;
	}
	_contact[i].setFirstName(in);
	std::cout << _contact[i].getFirstName() << std::endl;
	std::cout << "LAST NAME > ";
	std::getline(std::cin, in);
	_contact[i].setLastName(in);
	std::cout << _contact[i].getLastName() << std::endl;
	std::cout << "NICKNAME > ";
	std::getline(std::cin, in);
	_contact[i].setNickname(in);
	std::cout << _contact[i].getNickname() << std::endl;
	std::cout << "PHONE NUMBER > ";
	std::getline(std::cin, in);
	_contact[i].setPhoneNumber(in);
	std::cout << _contact[i].getPhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET > ";
	std::getline(std::cin, in);
	_contact[i].setDarkestSecret(in);
	std::cout << _contact[i].getDarkestSecret() << std::endl;
	std::cout << i << std::endl;
}

void	Phonebook::Search(void)
{
	
}

int main( ){
	
	int i = 0;
	Phonebook contact_list;
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
			contact_list.Add_info(in, i);
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