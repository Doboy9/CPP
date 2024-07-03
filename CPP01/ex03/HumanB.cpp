/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:32:17 by dboire            #+#    #+#             */
/*   Updated: 2024/06/30 14:02:04 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}


void HumanB::attack()
{
	std::cout << _name;
	if(_weapon)
	{
		std::cout << " attacks with their "
		<<  _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << " attacks with their fists" << std::endl; 
	}
}