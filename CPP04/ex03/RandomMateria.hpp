/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomMateria.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:12:08 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:27:59 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMMATERIA_HPP
# define RANDOMMATERIA_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class ICharacter;

class RandomMateria : public AMateria{
private:
	std::string _type;
public:
	RandomMateria();
	~RandomMateria();
	RandomMateria(const RandomMateria &other);
	RandomMateria &operator=(const RandomMateria &other);
	
	void use(ICharacter& target);
	RandomMateria *clone() const;
	std::string const &get_type() const;
};

#endif