/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:48:28 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:40:24 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Animal;
class Brain;

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
	
	Brain *get_brain() const;
	void makeSound() const;
};

#endif