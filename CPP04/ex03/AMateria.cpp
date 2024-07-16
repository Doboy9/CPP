/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:52 by dboire            #+#    #+#             */
/*   Updated: 2024/07/16 15:56:30 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//MateriaSource

MateriaSource::MateriaSource(){};
MateriaSource::~MateriaSource(){};

void MateriaSource::learnMateria(AMateria *){}
AMateria* MateriaSource::createMateria(std::string const &type){
	if(type == "ice")
		return(new Ice());
	else if(type == "cure")
		return(new Cure());
	else
		return (NULL);
}

//AMateria

AMateria::AMateria(){};

AMateria::~AMateria(){};

AMateria::AMateria(std::string const &type){
	this->_type = type;
}

std::string const &AMateria::getType() const{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	return ;
}

//Character
Character::Character(){};
Character::~Character(){};

Character::Character(std::string &name)
{
	this->_name = name;
}

std::string const &Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	return ;
}

void Character::unequip(int idx)
{
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	return ;
}

//Cure

Cure::Cure(){};
Cure::~Cure(){};

void Cure::use(ICharacter &target)
{
	(void)target;
	std::cout << "* heals " << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return(new Cure(*this));
}

//Ice

Ice::Ice(){};
Ice::~Ice(){};

void Ice::use(ICharacter &target)
{
	(void)target;
	std::cout << "* shoots an ice bolt at "  << " *" << std::endl;
}

AMateria* Ice::clone() const{
	return(new Ice(*this));
}