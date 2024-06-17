/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:44:41 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 17:42:14 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

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
}

void	Phonebook::Show_Contact(int i)
{
	if (_contact[i].getFirstName().empty())
	{
		std::cout << "No one registered at this index" << std::endl;
		return ;
	}
	std::cout << "First Name : " << _contact[i].getFirstName() << std::endl;
	std::cout << "Last Name : " << _contact[i].getLastName() << std::endl;
	std::cout << "Nickname : " << _contact[i].getNickname() << std::endl;
	std::cout << "Phone Number : " << _contact[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << _contact[i].getDarkestSecret() << std::endl;
}

void	Phonebook::Search(void)
{
	std::string in;
	bool loop = true;
	
	std::cout << std::string(46, '*') << std::endl;
	std::cout << "*" << std::setw(11) << "Index|" << "First Name|" << " Last Name|" << "   Nickname*" << std::endl;
	std::cout << std::string(46, '*') << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::cout << "*" << std::setw(10) << i + 1 << "|";
		if(_contact[i].getFirstName().length() > 10)
			std::cout << _contact[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::string(10 - _contact[i].getFirstName().length(), ' ') << _contact[i].getFirstName() << "|";
		if(_contact[i].getLastName().length() > 10)
			std::cout << _contact[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::string(10 - _contact[i].getLastName().length(), ' ') << _contact[i].getLastName() << "|";
		if(_contact[i].getNickname().length() > 10)
			std::cout << _contact[i].getNickname().substr(0, 10) << ".*" << std::endl;
		else
			std::cout << std::string(11 - _contact[i].getNickname().length(), ' ') << _contact[i].getNickname() << "*" << std::endl;
	}
	std::cout << std::string(46, '*') << std::endl;
	std::cout << "Which contact would you want to see the informations ? " << std::endl;
	while(loop == true)
	{
		if (!std::getline(std::cin, in))
			exit(1);
		if (in[1] || in[0] == '0' || in[0] == '9' || isdigit(in[0]) == 0)
			std::cout << "Please type a number between 1 and 8" << std::endl <<"Which contact would you want to see the informations ? " << std::endl;
		if (in[0] && !in[1])
		{
			for(int i = 0; i < 8; i++)
			{
				if(in[0] == '0' + (i + 1))
				{
					Show_Contact(i);
					loop = false;
				}
			}
		}
	}
}