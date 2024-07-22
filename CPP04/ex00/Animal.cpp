/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:26 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 15:59:07 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor of animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default destructor of animal" << std::endl;
}

Animal::Animal(std::string const &type)
{
	this->_type = type;
}

Animal::Animal(const Animal &other)
{
	this->_type = other._type;
}

Animal Animal::operator=(const Animal &other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	std::cout << "Printing type : " << _type << std::endl;
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "An animal is making a sound" << std::endl;
}
