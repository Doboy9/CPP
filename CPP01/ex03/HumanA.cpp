/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:20:37 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 15:20:37 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : _name(name), _weapon(type)
{};

HumanA::~HumanA(){};

void HumanA::attack()
{
	std::cout << _name
	<< " attacks with their " 
	<<  _weapon.getType() << std::endl;
}