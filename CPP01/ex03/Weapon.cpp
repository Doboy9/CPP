/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:04:24 by dboire            #+#    #+#             */
/*   Updated: 2024/06/19 13:39:39 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	if (str.empty())
		_type = "fists";
	else
		_type = str;
};


const std::string &Weapon::getType()
{
	return(_type);
}

void Weapon::setType(std::string str)
{
	if (str.empty())
		_type = "fists";
	else
		_type = str;
}

Weapon::~Weapon(){};