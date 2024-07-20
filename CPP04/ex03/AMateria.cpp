/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:52 by dboire            #+#    #+#             */
/*   Updated: 2024/07/20 11:48:46 by dboire           ###   ########.fr       */
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

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for(int i = 0; i < 4; i++)
	{
		if(other._learned_materia[i])
			this->_learned_materia[i] = other._learned_materia[i];
		else
			this->_learned_materia[i] = 0;
	}
	std::cout << "Copy constructor of MateriaSource" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if(this != &other)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->_learned_materia[i])
				delete _learned_materia[i];
			if (other._learned_materia[i])
				this->_learned_materia[i] = other._learned_materia[i]->clone();
			else if(!this->_learned_materia[i])
				this->_learned_materia[i] = 0;
		}
	}
	return (*this);
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
		if(i == 3 && _learned_materia[3] != m)
			delete m;
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
	std::cout << " !Not a valid type! " << type << std::endl;
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

Character::Character(const Character &other) : _name(other.getName()), materia(NULL), next(NULL), head(NULL)
{
	for(int i = 0; i < 4; i++)
	{
		if(other._stock[i])
			this->_stock[i] = other._stock[i]->clone();
		else
			this->_stock[i] = 0;
	}
	this->_name += ".copy";
	std::cout << "Deep copy of the character created : "<< this->getName() << std::endl;
}

Character &Character::operator=(const Character &other)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_stock[i])
			delete _stock[i];
		if (other._stock[i])
			this->_stock[i] = other._stock[i]->clone();
		else if(!this->_stock[i])
			this->_stock[i] = 0;
	}
	return(*this);
}

Character::Character(): _name(""), materia(NULL), next(NULL), head(NULL)
{
	for(int i = 0; i < 4; i++)
		this->_stock[i] = 0;
	std::cout << "Default constructor of Character" << std::endl;
}

Character::~Character()
{
	Character *current = head;
	while(current != NULL)
	{
		Character *next = current->next;
		delete current->materia;
		delete current;
		current = next;
	}
	for(int i = 0; i < 4; i++)
	{
		if(this->_stock[i])
			delete this->_stock[i];
	}
	std::cout << "Default destructor of Character " << this->getName() << std::endl;
}

Character::Character(const std::string &name) : _name(name), materia(NULL), next(NULL), head(NULL)
{
	for(int i = 0; i < 4; i++)
		this->_stock[i] = 0;
	std::cout << "Parameter constructor of Character" << std::endl;
}

std::string const &Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	std::cout << "Character::Equip : ";
	if(!m)
	{
		std::cout << "No materia passed" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if(!_stock[i])
		{
			std::cout << i << " Equipping " << m->getType() << std::endl;
			this->_stock[i] = m;
			return ;
		}
	}
	if(_stock[3] && _stock[3] != m)
	{
		std::cout << "Inventory full, deleting " << m->getType() << std::endl;
		delete m;
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
		Character *floor_stock = new Character;
		floor_stock->materia = _stock[idx];
		floor_stock->next = NULL;
		if(head == NULL)
			head = floor_stock;
		else
		{
			Character *tmp = head;
			while(tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = floor_stock;
		}
		_stock[idx] = NULL;
		std::cout << "Character::unequip" << std::endl;
	}
	else
	{
		std::cout << "Slot empty, nothing to unequip" << std::endl;
	}
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx >= 0 && idx < 4 && _stock[idx] != NULL)
	{
		std::cout << "Character " << this->getName() << " use " << this->get_stock(idx)->getType() << " on " << target.getName() << std::endl;
		this->get_stock(idx)->use(target);
		this->unequip(idx);
		return ;
	}
	if(_stock[idx] == NULL)
	{
		std::cout << "Nothing in this slot !" << std::endl;
	}
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

//Ice

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

// Random_Materia

Random_Materia::Random_Materia() : AMateria("random materia")
{
	std::cout << "Default constructor of Random_Materia" << std::endl;
}

Random_Materia::~Random_Materia()
{
	std::cout << "Default destructor of Random_Materia" << std::endl;
}

Random_Materia::Random_Materia(const Random_Materia &other) : AMateria(other.getType())
{
	std::cout << "Copy constructor of " << this->getType() << std::endl;
}

Random_Materia &Random_Materia::operator=(const Random_Materia &other)
{
	if(this != &other)
		AMateria::operator=(other);
	return(*this);
}

void Random_Materia::use(ICharacter &target)
{
	std::cout << "* " << target.getName()  << " is doing something with a random materia *" << std::endl;
}

Random_Materia *Random_Materia::clone() const
{
	return(new Random_Materia(*this));
}

std::string const &Random_Materia::get_type() const{
	return(this->_type);
}
