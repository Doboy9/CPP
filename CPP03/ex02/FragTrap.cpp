/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:56:47 by dboire            #+#    #+#             */
/*   Updated: 2024/07/12 14:40:04 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destroying FragTrap " << this->get_name() << " in FragTrap destructor" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	set_hit_points(90);
	set_energy_points(90);
	set_attack_damage(30);
	std::cout << name << " is created in the FragTrap constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
}

FragTrap FragTrap::operator=(const FragTrap &other)
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

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << this->get_name() << " HP : " << get_hit_points() << std::endl;
	if (this->get_hit_points() <= 0)
	{
		std::cout << this->get_name() << " is dead !" << std::endl;
		return ;
	}
	if (this->get_energy_points() <= 0)
	{
		std::cout << this->get_name() << " is out of energy !" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->get_name() << " attack " << target << " causing " << this->get_attack_damage() << " points of damage"  << std::endl;
	this->set_energy_points(-1);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap is requesting a High Five" << std::endl;
}