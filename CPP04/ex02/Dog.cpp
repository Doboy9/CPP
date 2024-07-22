/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:51:11 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:24:54 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include"Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Default constructor of Dog" << std::endl;
}

Dog::Dog(std::string const &name) : Animal(name)
{
	this->brain = new Brain();
	_type = "Dog";
	std::cout << "Parameter constructor of Dog" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->brain = new Brain();
	_type = other._type;
	std::cout << "Copy constructor of Dog" << std::endl;
}

Dog Dog::operator=(const Dog &other)
{
	if(this != &other)
	{
		this->_type = other._type;
		*this->brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Default destructor of Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog is barking" << std::endl;
}

Brain *Dog::get_brain() const
{
	return(this->brain);
}