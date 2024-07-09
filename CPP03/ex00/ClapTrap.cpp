/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:44:41 by dboire            #+#    #+#             */
/*   Updated: 2024/07/09 18:17:20 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){};

ClapTrap::ClapTrap(std::string &name) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	this->_name = name; 
	std::cout << "ClapTrap is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap is destroyed" << std::endl;
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
	this->set_energy_points(1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->set_hit_points(amount * -1);
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
	this->set_hit_points(amount);
	std::cout << "Regenerating life to : " << this->_hit_points << std::endl;
	this->set_energy_points(1);
}

std::string ClapTrap::get_name()
{
	return (this->_name);
}

// Hit_points Getter/Setter

int ClapTrap::get_hit_points()
{
	return(this->_hit_points);
}

void ClapTrap::set_hit_points(int value)
{
	this->_hit_points = this->get_hit_points() + value;
}

// Energy_points Getter/Setter

unsigned int ClapTrap::get_energy_points()
{
	return(this->_energy_points);
}

void ClapTrap::set_energy_points(int value)
{
	this->_energy_points = this->_energy_points - value;
	
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