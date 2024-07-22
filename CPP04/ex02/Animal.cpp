/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:26 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:07:20 by dboire           ###   ########.fr       */
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
	std::cout << "Parameter constructor of animal" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->_type = other._type;
	std::cout << "Copy constructor of animal" << std::endl;
}

std::string Animal::getType() const
{
	std::cout << "Printing type : " << _type << std::endl;
	return (_type);
}

Brain *Animal::get_brain() const 
{
	return(NULL);
}
