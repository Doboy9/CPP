/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:19:19 by dboire            #+#    #+#             */
/*   Updated: 2024/06/30 14:02:28 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA 
{

private:
	std::string _name;
	Weapon &_weapon;

public:
	HumanA(std::string name, Weapon &type);
	~HumanA();
	
	void attack();
};


# endif 