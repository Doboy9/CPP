/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomMateria.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:14:33 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:39:06 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomMateria.hpp"

RandomMateria::RandomMateria() : AMateria("random materia")
{
	std::cout << "Default constructor of RandomMateria" << std::endl;
}

RandomMateria::~RandomMateria()
{
	std::cout << "Default destructor of RandomMateria" << std::endl;
}

RandomMateria::RandomMateria(const RandomMateria &other) : AMateria(other.getType())
{
	std::cout << "Copy constructor of " << this->getType() << std::endl;
}

RandomMateria &RandomMateria::operator=(const RandomMateria &other)
{
	if(this != &other)
		AMateria::operator=(other);
	return(*this);
}

void RandomMateria::use(ICharacter &target)
{
	std::cout << "* " << target.getName()  << " is doing something with a random materia *" << std::endl;
}

RandomMateria *RandomMateria::clone() const
{
	return(new RandomMateria(*this));
}

std::string const &RandomMateria::get_type() const{
	return(this->_type);
}
