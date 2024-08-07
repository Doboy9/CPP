/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:50 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:30:11 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(std::string const &type);
	std::string const &getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);
	virtual ~AMateria();
	AMateria(AMateria const &ref);
	AMateria &operator=(const AMateria &other);
};

#endif