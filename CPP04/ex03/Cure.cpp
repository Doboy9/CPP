/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:26:13 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:34:43 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default constructor of Cure" << std::endl;
}
Cure::~Cure()
{
	std::cout << "Default destructor of Cure" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other.getType())
{
	std::cout << "Copy constructor of " << this->getType() << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if(this != &other)
		AMateria::operator=(other);
	return(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure *Cure::clone() const
{
	return(new Cure(*this));
}

std::string const &Cure::get_type() const
{
	return(this->_type);
}