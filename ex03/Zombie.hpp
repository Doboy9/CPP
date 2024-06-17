/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:56:28 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 08:56:28 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include<string>


class Zombie
{

private:

	std::string _name;


public:

	Zombie(){};
	~Zombie(){};

void Announce(void);


};

# endif