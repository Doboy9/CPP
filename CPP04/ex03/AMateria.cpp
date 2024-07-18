/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:52 by dboire            #+#    #+#             */
/*   Updated: 2024/07/18 18:51:35 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//MateriaSource

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		_learned_materia[i] = 0;
	}
	std::cout << "Default constructor of MateriaSource" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		if(_learned_materia[i])
		{
			delete _learned_materia[i];
			_learned_materia[i] = NULL;
		}
	}
	std::cout << "Default destructor of MateriaSource" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if(!m)
	{
		std::cout << "Cannot learn a NULL Materia" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if(!_learned_materia[i])
		{
			_learned_materia[i] = m;
			return ;
		}
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if(_learned_materia[i] != NULL && _learned_materia[i]->getType() == type)
			return (_learned_materia[i]->clone());
	}
	return(NULL);
}

//AMateria

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

//Character

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if(this->_stock[i])
			delete this->_stock[i];
	}
	std::cout << "Default destructor of Character " << this->getName() << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for(int i = 0; i < 4; i++)
		this->_stock[i] = 0;
	std::cout << "Default constructor of Character" << std::endl;
}

std::string const &Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	std::cout << "Character::Equip" << std::endl;
	if(!m)
	{
		std::cout << "No materia passed" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if(!_stock[i])
		{
			std::cout << i;
			this->_stock[i] = m;
			return ;
		}
	}
	return ;
}

AMateria *Character::get_stock(int idx)
{
	return(this->_stock[idx]);
}

void Character::unequip(int idx)
{
	if(idx >= 0 && idx < 4 && _stock[idx] != NULL)
	{
		AMateria *i = _stock[idx];
		_stock[idx] = NULL;
		Materia_stock *stock = new Materia_stock;
		stock->materia = i;
		stock->next = materia;
		materia = stock;
		std::cout << "Character::unequip" << std::endl;
	}
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << "Character " << this->getName() << " use " << this->get_stock(idx)->getType() << " on " << target.getName() << std::endl;
	this->get_stock(idx)->use(target);
	this->unequip(idx);
	return ;
}

//Cure

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default constructor of Cure" << std::endl;
}
Cure::~Cure()
{
	std::cout << "Default destructor of Cure" << std::endl;
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

//Ice

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default constructor of Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Default destructor of Ice" << std::endl;
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