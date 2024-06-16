/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:46:35 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 11:27:38 by dboire           ###   ########.fr       */
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
	bool loop = true;
	while(true)
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
	while(true)
	{
		std::cout << "LAST NAME > ";
		if (!std::getline(std::cin, in))
 			exit(1);
		if(in.empty())
			std::cout << "No empty informations" << std::endl;
		else
			break ;
	}
	_contact[i].setLastName(in);
	std::cout << _contact[i].getLastName() << std::endl;
	while(true)
	{
		std::cout << "NICKNAME > ";
		if (!std::getline(std::cin, in))
 			exit(1);
		if(in.empty())
			std::cout << "No empty informations" << std::endl;
		else
			break ;
	}
	_contact[i].setNickname(in);
	std::cout << _contact[i].getNickname() << std::endl;
	while(loop == true)
	{
		std::cout << "PHONE NUMBER > ";
		if (!std::getline(std::cin, in))
 			exit(1);
		if(in.empty())
			std::cout << "No empty informations" << std::endl;
		else
		{
			loop = false;
			for(int j = 0; in[j]; j++)
			{
				if(isdigit(in[j]) == 0)
				{
					if (loop != true)
						std::cout << "Insert phone number" << std::endl;
					loop = true;
				}
			}
		}
	}
	_contact[i].setPhoneNumber(in);
	std::cout << _contact[i].getPhoneNumber() << std::endl;
	while(1)
	{
		std::cout << "DARKEST SECRET > ";
		if (!std::getline(std::cin, in))
 			exit(1);
		if(in.empty())
			std::cout << "No empty informations" << std::endl;
		else
			break ;
	}
	_contact[i].setDarkestSecret(in);
	std::cout << _contact[i].getDarkestSecret() << std::endl;
	std::cout << i << std::endl;
}

void	Phonebook::Search(void)
{
	std::cout << std::string(46, '*') << std::endl;
	std::cout << "*" << std::string(5, ' ') << "Index|" << "First Name|" << " Last Name|" << "   Nickname*" << std::endl;
	std::cout << std::string(46, '*') << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::cout << "*" << std::string(9, ' ') << i + 1 << "|" << std::string(10 - _contact[i].getFirstName().length(), ' ') << _contact[i].getFirstName() << "|";
		std::cout << std::string(10 - _contact[i].getLastName().length(), ' ') << _contact[i].getLastName() << "|";
		std::cout << std::string(11 - _contact[i].getNickname().length(), ' ') << _contact[i].getNickname() << "*" << std::endl;

	}
	std::cout << std::string(46, '*') << std::endl;
}

int main(){
	
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
			contact_list.Search();
		}
		if (in == "EXIT")
		{
			exit(0);
		}
	}
}