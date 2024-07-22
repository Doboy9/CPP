/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:23 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:39:48 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Brain;

class Animal {
protected : 
	std::string _type;

public :
	Animal();
	virtual ~Animal();
	Animal(std::string const &type);
	Animal(const Animal &other);
	Animal	operator=(const Animal &other);

	virtual void makeSound() const;
	virtual Brain *get_brain() const;
	std::string getType() const;
};

#endif