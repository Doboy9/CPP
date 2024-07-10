/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:47:25 by dboire            #+#    #+#             */
/*   Updated: 2024/07/10 11:23:39 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destroying ScavTrap " << this->get_name() << " in ScavTrap destructor" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	set_hit_points(90);
	set_energy_points(40);
	set_attack_damage(20);
	std::cout << name << " is created in the ScavTrap constructor" << std::endl;
}

void	ScavTrap::guardgate()
{
	std::cout << this->get_name() << " is now in gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << this->get_name() << " HP : " << get_hit_points() << std::endl;
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
	std::cout << "ScavTrap " << this->get_name() << " attack " << target << " causing " << this->get_attack_damage() << " points of damage"  << std::endl;
	this->set_energy_points(-1);
}