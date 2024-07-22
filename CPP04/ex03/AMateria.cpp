/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:52 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:28:42 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::~AMateria()
{
	std::cout << "AMateria of type " << _type << " destroyed" << std::endl;
	std::cout << "Default destructor of AMateria" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria of type " << _type << " constructed" << std::endl;
}

AMateria::AMateria(AMateria const &ref)
{
	_type = ref._type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if(this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const &AMateria::getType() const{
	return(_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
	return ;
}