/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:44:41 by dboire            #+#    #+#             */
/*   Updated: 2024/07/12 15:39:22 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){};

ClapTrap::ClapTrap(const std::string &name) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	this->_name = name; 
	std::cout << "ClapTrap is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap is destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	std::cout << "ClapTrap copy constructor created" << std::endl;
}

ClapTrap ClapTrap::operator=(const ClapTrap &other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "HP : " << get_hit_points() << std::endl;
	if (this->get_hit_points() <= 0)
	{
		std::cout << "ClapTrap is dead !" << std::endl;
		return ;
	}
	if (this->get_energy_points() <= 0)
	{
		std::cout << "ClapTrap is out of energy !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attack " << target << " causing " << this->get_attack_damage() << " points of damage"  << std::endl;
	this->change_energy_points(-1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->change_hit_points(-amount);
	std::cout << "Took damage : " << amount << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->get_hit_points() <= 0)
	{
		std::cout << "ClapTrap is dead !" << std::endl;
		return ;
	}
	if (this->get_energy_points() <= 0)
	{
		std::cout << "ClapTrap is out of energy !" << std::endl;
		return ;
	}
	std::cout << "Repairing " << amount << std::endl;
	this->change_hit_points(amount);
	std::cout << "Regenerating life to : " << this->get_hit_points() << std::endl;
	this->change_energy_points(-1);
}

std::string ClapTrap::get_name()
{
	std::cout << "Name : " << this->_name << std::endl;
	return (this->_name);
}

// Hit_points Getter/Setter/Modifier

int ClapTrap::get_hit_points()
{
	return(this->_hit_points);
}

void ClapTrap::set_hit_points(int value)
{
	this->_hit_points = value;
}

void ClapTrap::change_hit_points(int value)
{
	this->set_hit_points(this->get_hit_points() + value);
}

// Energy_points Getter/Setter/Modifier

unsigned int ClapTrap::get_energy_points()
{
	return(this->_energy_points);
}

void ClapTrap::set_energy_points(int value)
{
	this->_energy_points = value;
	
}

void	ClapTrap::change_energy_points(int value)
{
	this->set_energy_points(this->get_energy_points() + value);
}

// Attack_damage Getter/Setter

unsigned int ClapTrap::get_attack_damage()
{
	return(this->_attack_damage);
}

void ClapTrap::set_attack_damage(int value)
{
	this->_attack_damage = value;
}