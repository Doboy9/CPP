/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:51:08 by dboire            #+#    #+#             */
/*   Updated: 2024/07/23 12:25:20 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor of Wronganimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor of Wronganimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type)
{
	this->_type = type;
	std::cout << "Parameter constructor of Wronganimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->_type = other._type;
	std::cout << "Copy constructor of Wronganimal" << std::endl;
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
	std::cout << "An Wronganimal is making a sound" << std::endl;
}

Brain *WrongAnimal::get_brain() const 
{
	return(NULL);
}