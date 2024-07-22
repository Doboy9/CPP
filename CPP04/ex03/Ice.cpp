/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:26:37 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:34:36 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default constructor of Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Default destructor of Ice" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other.getType())
{
	std::cout << "Copy constructor of " << this->getType() << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if(this != &other)
		AMateria::operator=(other);
	return(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()  << " *" << std::endl;
}

Ice *Ice::clone() const
{
	return(new Ice(*this));
}

std::string const &Ice::get_type() const{
	return(this->_type);
}