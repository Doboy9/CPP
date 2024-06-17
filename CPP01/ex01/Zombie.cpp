/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:36:30 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 12:56:51 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::Naming(std::string name)
{
	_name = name;
}
Zombie::Zombie(){};

Zombie::~Zombie()
{
	std::cout << _name << ":Died" << std::endl;
}