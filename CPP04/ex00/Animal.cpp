/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:26 by dboire            #+#    #+#             */
/*   Updated: 2024/07/12 15:49:26 by dboire           ###   ########.fr       */
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

// Cat

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
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_type = other._type;
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

// Dog

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default constructor of Dog" << std::endl;
}

Dog::Dog(std::string const &name) : Animal(name)
{
	_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	
	_type = other._type;
}

Dog Dog::operator=(const Dog &other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Default destructor of Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog is barking" << std::endl;
}

//Wrong Animal

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
	std::cout << "A WrongAnimal is making a sound" << std::endl;
}

// Wrong Cat

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