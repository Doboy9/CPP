/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:51:08 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:57:25 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor of WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type)
{
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->_type = other._type;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal &other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string WrongAnimal::getType() const
{
	std::cout << "Printing type : " << _type << std::endl;
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "An WrongAnimal is making a sound" << std::endl;
}