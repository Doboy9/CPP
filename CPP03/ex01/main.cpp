/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:44:45 by dboire            #+#    #+#             */
/*   Updated: 2024/07/10 10:13:37 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
	ClapTrap claptrap("Clap");
	ScavTrap scavtrap("ScaTra");
	
	
	scavtrap.guardgate();
	scavtrap.attack("someone");
	scavtrap.takeDamage(60);
	scavtrap.beRepaired(60);
	claptrap.attack("someone");
	claptrap.beRepaired(10);
	claptrap.takeDamage(15);
	claptrap.attack("someone else");
	claptrap.beRepaired(50);
	claptrap.attack("someone else");
	claptrap.attack("someone else");
	claptrap.attack("someone else");
	claptrap.attack("someone else");
	claptrap.attack("someone else");
	claptrap.attack("someone else");
	claptrap.attack("someone else");
	claptrap.takeDamage(1000);
	claptrap.attack("someone else");
}