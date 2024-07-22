/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:09 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:33:36 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include"AMateria.hpp"
#include"ICharacter.hpp"
class AMateria;
class ICharacter;

class Ice : public AMateria{
private:
	std::string _type;
public:
	Ice();
	~Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	
	void use(ICharacter& target);
	Ice *clone() const;
	std::string const &get_type() const;
};

#endif