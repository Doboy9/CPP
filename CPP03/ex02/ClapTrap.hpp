/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:44:43 by dboire            #+#    #+#             */
/*   Updated: 2024/07/10 09:23:14 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

private:
	std::string _name;
	int 		_hit_points;
	int 		_energy_points;
	int 		_attack_damage;


public:
	ClapTrap();
	ClapTrap(std::string const &name);
	virtual ~ClapTrap();

	std::string		get_name();
	int				get_hit_points();
	unsigned int	get_energy_points();
	unsigned int	get_attack_damage();
	void			set_hit_points(int value);
	void			set_energy_points(int value);
	void			set_attack_damage(int value);


	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
    
};

#endif