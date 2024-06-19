/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:20:25 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 13:24:42 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon 
{

private:
	std::string _type;

public:

	Weapon(std::string str);
	~Weapon();

	const std::string &getType();
	void setType(std::string str);

};


# endif 