/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:23 by dboire            #+#    #+#             */
/*   Updated: 2024/07/10 14:58:09 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
private : 
	std::string _type;

public :
	Animal();
	virtual ~Animal();
	void makeSound();
};

class Dog : public Animal
{

	Dog();
	~Dog();
};

class Cat : public Animal
{
	Cat();
	~Cat();
};


#endif