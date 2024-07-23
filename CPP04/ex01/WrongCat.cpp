/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:51:05 by dboire            #+#    #+#             */
/*   Updated: 2024/07/23 12:29:30 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	this->brain = new Brain();
	std::cout << "Default constructor of WrongCat" << std::endl;
}

WrongCat::WrongCat(std::string const &name) : WrongAnimal(name)
{
	this->brain = new Brain();
	_type = "WrongCat";
	std::cout << "Parameter constructor of WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->brain = other.get_brain();
	_type = other._type;
	std::cout << "Copy constructor of Cat" << std::endl;
}

WrongCat WrongCat::operator=(const WrongCat &other)
{
	if(this != &other)
	{
		this->_type = other._type;
		*this->brain = *other.brain;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	delete this->brain;
	std::cout << "Default destructor of WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat is meowing" << std::endl;
}

Brain *WrongCat::get_brain() const
{
	return(this->brain);
}