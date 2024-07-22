/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:48:28 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 16:51:02 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Animal;

class Dog : public Animal
{
private: 

public:
	Dog();
	Dog(std::string const &type);
	Dog(const Dog &other);
	Dog	operator=(const Dog &other);
	~Dog();
	
	void makeSound() const;
};

#endif