/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:31:55 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 15:31:55 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include <iostream>

class HumanB
{

private:
	std::string _name;
	Weapon *_weapon;

public:

	HumanB(std::string name);
	~HumanB();
	
	void attack();
	void setweapon(Weapon weapon);
};


# endif 