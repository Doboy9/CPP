/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:44:41 by dboire            #+#    #+#             */
/*   Updated: 2024/07/09 16:12:24 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10), _energy_points(10), _attack_damage(0)
{
   std::cout << "ClapTrap is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap is destroyed" << std::endl;
}

