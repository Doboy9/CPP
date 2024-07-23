/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:45:23 by dboire            #+#    #+#             */
/*   Updated: 2024/07/23 13:09:56 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

//Animal class

class Brain;

class Animal {
	
private:
	Animal();

protected : 
	std::string _type;
	std::string _name;

public :
	virtual ~Animal();
	Animal(std::string const &type);
	Animal(const Animal &other);
	Animal	operator=(const Animal &other);

	virtual void makeSound() const = 0;
	virtual Brain *get_brain() const;
	std::string getType() const;
};

#endif