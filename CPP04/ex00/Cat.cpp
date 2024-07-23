/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:51:13 by dboire            #+#    #+#             */
/*   Updated: 2024/07/23 13:14:47 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"
#include"Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default constructor of Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default destructor of Cat" << std::endl;
}

Cat::Cat(std::string const &name) : Animal(name)
{
	_type = "Cat";
	std::cout << "Parameter constructor of Cat" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_type = other._type;
	std::cout << "Copy constructor of Cat" << std::endl;
}

Cat Cat::operator=(const Cat &other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat is meowing" << std::endl;
}