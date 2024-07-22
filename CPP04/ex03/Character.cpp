/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:25:48 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:34:51 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

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