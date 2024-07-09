/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:44:45 by dboire            #+#    #+#             */
/*   Updated: 2024/07/09 18:17:19 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	std::string str = "1";

	ClapTrap claptrap(str);
	
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