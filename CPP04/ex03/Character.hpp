/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:18:35 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 18:38:05 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include"AMateria.hpp"
#include"ICharacter.hpp"

class ICharacter;
class AMateria;

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_stock[4];
	Character();

public:
	Character(const std::string &name);
	Character(const Character &other);
	Character	&operator=(const Character &other);
	
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria *get_stock(int idx);
	AMateria *materia;
	Character *next;
	Character *head;
	~Character();
};

#endif