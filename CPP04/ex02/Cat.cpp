/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:51:13 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:51:54 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"
#include"Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain();
	std::cout << "Default constructor of Cat" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Default destructor of Cat" << std::endl;
}

Cat::Cat(std::string const &name) : Animal(name)
{
	this->brain = new Brain();
	_type = "Cat";
	std::cout << "Parameter constructor of Cat" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->brain = new Brain();
	_type = other._type;
	std::cout << "Copy constructor of Cat" << std::endl;
}

Cat Cat::operator=(const Cat &other)
{
	if(this != &other)
	{
		this->_type = other._type;
		*this->brain = *other.brain;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat is meowing" << std::endl;
}

Brain *Cat::get_brain() const
{
	return(this->brain);
}