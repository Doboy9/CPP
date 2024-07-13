/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:47:27 by dboire            #+#    #+#             */
/*   Updated: 2024/07/13 14:32:02 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private :
	ScavTrap();


public :

	ScavTrap(std::string const &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap	operator=(const ScavTrap &other);
	~ScavTrap();

	void	guardGate();
	void	attack(const std::string &target);

};





#endif