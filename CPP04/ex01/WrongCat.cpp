/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:51:05 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:36:24 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor of WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Default destructor of WrongCat" << std::endl;
}

WrongCat::WrongCat(std::string const &name) : WrongAnimal(name)
{
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->_type = other._type;
}

WrongCat WrongCat::operator=(const WrongCat &other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat is talking in human language" << std::endl;
}
