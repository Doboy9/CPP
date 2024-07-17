/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:52 by dboire            #+#    #+#             */
/*   Updated: 2024/07/16 17:37:02 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//MateriaSource

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor of MateriaSource" << std::endl;
}
MateriaSource::~MateriaSource()
{
	std::cout << "Default destructor of MateriaSource" << std::endl;
}

void MateriaSource::learnMateria(AMateria *){};

AMateria* MateriaSource::createMateria(std::string const &type){
	if(type == "ice")
		return(new Ice());
	else if(type == "cure")
		return(new Cure());
	else
		return (NULL);
}

//AMateria

AMateria::AMateria()
{
	std::cout << "Default constructor of AMateria" << std::endl;
}
AMateria::~AMateria()
{
	std::cout << "Default destructor of AMateria" << std::endl;
}

AMateria::AMateria(std::string const &type){
	this->_type = type;
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
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
	return ;
}

//Character
Character::Character()
{
	for(int i = 0; i < 4; i++)
		this->_stock[i] = 0;
	std::cout << "Default constructor of Character" << std::endl;
}
Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if(this->_stock[i])
			delete this->_stock[i];
	}
	std::cout << "Default destructor of Character " << this->getName() << std::endl;
}

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
			std::cout << i << std::endl;
			_stock[i] = m;
			return ;
		}
	}
	std::cout << "Character::equip" << std::endl;
	return ;
}

AMateria *Character::get_stock(int idx)
{
	return(this->_stock[idx]);
}

void Character::unequip(int idx)
{
	(void)idx;
	std::cout << "Character::unequip" << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
	std::cout << "Character::use" << std::endl;
	return ;
}

//Cure

Cure::Cure()
{
	std::cout << "Default constructor of Cure" << std::endl;
}
Cure::~Cure()
{
	std::cout << "Default destructor of Cure" << std::endl;
}

void Cure::use(ICharacter &target)
{
	(void)target;
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

Ice::Ice(){
	std::cout << "Default constructor of Ice" << std::endl;
}
Ice::~Ice(){
	std::cout << "Default destructor of Ice" << std::endl;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()  << " *" << std::endl;
}

Ice *Ice::clone() const{
	return(new Ice(*this));
}

std::string const &Ice::get_type() const{
	return(this->_type);
}