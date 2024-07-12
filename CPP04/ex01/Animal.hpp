/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:23 by dboire            #+#    #+#             */
/*   Updated: 2024/07/11 19:03:21 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected : 
	std::string _type;
	std::string _name;

public :
	Animal();
	virtual ~Animal();
	Animal(std::string const &type);
	Animal(const Animal &other);
	Animal	operator=(const Animal &other);
	
	virtual void makeSound() const;
	std::string getType() const;
};

// Dog class

class Dog : public Animal
{
private: 
	Brain *brain;

public:
	Dog();
	Dog(std::string const &type);
	Dog(const Dog &other);
	Dog	operator=(const Dog &other);
	~Dog();
	
	void makeSound() const;
};

// Cat Class

class Cat : public Animal
{
private: 
	Brain *brain;

public:
	Cat();
	Cat(std::string const &type);
	Cat(const Cat &other);
	Cat	operator=(const Cat &other);
	~Cat();
	
	void makeSound() const;
};

//Wrong Animal class

class WrongAnimal {
protected : 
	std::string _type;
	std::string _name;

public :
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal	operator=(const WrongAnimal &other);
	
	virtual void makeSound() const;
	std::string getType() const;
};

// WrongCat class

class WrongCat : public WrongAnimal
{
private: 

public:
	WrongCat();
	WrongCat(std::string const &type);
	WrongCat(const WrongCat &other);
	WrongCat	operator=(const WrongCat &other);
	~WrongCat();
	
	void makeSound() const;
};

//Brain class

class Brain
{
private:
	std::string ideas[100];

public:

};

#endif