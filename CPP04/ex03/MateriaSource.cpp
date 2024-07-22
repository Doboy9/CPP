/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:25:10 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:34:18 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AMateria.hpp"
#include"MateriaSource.hpp"
#include"ICharacter.hpp"

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