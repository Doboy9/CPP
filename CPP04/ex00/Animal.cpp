/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:26 by dboire            #+#    #+#             */
/*   Updated: 2024/07/10 14:13:47 by dboire           ###   ########.fr       */
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

// Cat

Cat::Cat()
{
	std::cout << "Default constructor of Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default destructor of Cat" << std::endl;
}

// Dog

Dog::Dog()
{
	std::cout << "Default constructor of Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Default destructor of Dog" << std::endl;
}