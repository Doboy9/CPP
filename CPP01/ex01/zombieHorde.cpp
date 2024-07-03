/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:19:28 by dboire            #+#    #+#             */
/*   Updated: 2024/06/30 14:15:35 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if(N <= 0)
		return (NULL);
	Zombie *Horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		Horde[i].Naming(name);
		Horde[i].announce();
	}
	return (Horde);
}