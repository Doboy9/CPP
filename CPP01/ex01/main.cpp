/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:55:58 by dboire            #+#    #+#             */
/*   Updated: 2024/06/17 08:55:58 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	Zombie stack_z("FOO");
	Zombie *heap_z = newZombie("HEAP");
	
	randomChump("RANDOL");
	delete heap_z;
	return(0);
}