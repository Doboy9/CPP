/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:56:28 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 12:17:47 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>


class Zombie
{

private:

	std::string _name;


public:

	Zombie();
	~Zombie();

	void announce(void);
	void Naming(std::string name);
};

Zombie* zombieHorde( int N, std::string name );


# endif