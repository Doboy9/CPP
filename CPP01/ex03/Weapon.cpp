/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:04:24 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 15:04:24 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	getType(str);
}


void Weapon::getType(std::string str)
{
	_type = str;
}

void Weapon::setType(std::string str)
{
	_type = str;
}

Weapon::~Weapon(){};