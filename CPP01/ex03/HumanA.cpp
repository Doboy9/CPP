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
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon type)
{
	_name = name;
}

HumanA::~HumanA(){};

void HumanA::attack()
{
	std::cout << _name
	<< " attacks with their "
	//<< getType()
	;
}