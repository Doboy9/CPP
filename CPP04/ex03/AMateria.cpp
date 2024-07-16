/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:52 by dboire            #+#    #+#             */
/*   Updated: 2024/07/16 16:05:15 by dboire           ###   ########.fr       */
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
	(void)target;
	return ;
}

//Character
Character::Character(){};
Character::~Character(){};

Character::Character(const std::string &name)
{
	this->_name = name;
}

std::string const &Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	(void)m;
	return ;
}

void Character::unequip(int idx)
{
	(void)idx;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
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