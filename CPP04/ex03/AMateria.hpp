/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:01:50 by dboire            #+#    #+#             */
/*   Updated: 2024/07/16 17:35:52 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class AMateria;
class ICharacter;
class Character;
class IMateriaSource;
class MateriaSource;
class Ice;
class Cure;

class AMateria
{
protected:
	AMateria();
	std::string _type;

public:
	AMateria(std::string const &type);
	std::string const &getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	virtual ~AMateria();
	AMateria(AMateria const &ref);
	AMateria &operator=(const AMateria &other);
};

class ICharacter
{
public:
	virtual ~ICharacter() {};
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
private:
	Character();
	std::string _name;
	AMateria *_stock[4];

public:
	Character(const std::string &name);
	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria *get_stock(int idx);
	
	~Character();
};

class IMateriaSource
{
public:
	virtual ~IMateriaSource(){};
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource{
public :
	MateriaSource();
	~MateriaSource();
	void learnMateria(AMateria *);
	AMateria* createMateria(std::string const & type);
};

class Ice : public AMateria{
public:
	Ice();
	~Ice();
	void use(ICharacter& target);
	Ice *clone() const;
	std::string const &get_type() const;
};

class Cure : public AMateria{
private:
	std::string _type;
public:
	Cure();
	~Cure();
	void use(ICharacter& target);
	Cure *clone() const;
	std::string const &get_type() const;
};

#endif