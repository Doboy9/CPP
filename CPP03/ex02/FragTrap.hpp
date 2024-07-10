/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:58:45 by dboire            #+#    #+#             */
/*   Updated: 2024/07/10 11:15:31 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private :


public :

	FragTrap();
	FragTrap(std::string const &name);
	~FragTrap();

	void	attack(const std::string &target);
	void	highFivesGuys(void);

};

#endif