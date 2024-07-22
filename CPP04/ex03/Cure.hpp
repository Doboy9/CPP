/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:23:54 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:33:32 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include"AMateria.hpp"
#include"ICharacter.hpp"
class AMateria;
class ICharacter;

class Cure : public AMateria{
private:
	std::string _type;
public:
	Cure();
	~Cure();
	Cure(const Cure &other);
	Cure	&operator=(const Cure &other);
	
	void use(ICharacter& target);
	Cure *clone() const;
	std::string const &get_type() const;
};

#endif