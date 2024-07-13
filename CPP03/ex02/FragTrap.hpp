/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:58:45 by dboire            #+#    #+#             */
/*   Updated: 2024/07/13 14:32:32 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private :
	FragTrap();


public :

	FragTrap(std::string const &name);
	FragTrap(const FragTrap &other);
	FragTrap	operator=(const FragTrap &other);
	~FragTrap();

	void	attack(const std::string &target);
	void	highFivesGuys(void);

};

#endif