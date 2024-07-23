/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:49:47 by dboire            #+#    #+#             */
/*   Updated: 2024/07/23 13:04:56 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class Brain;

class WrongAnimal {
protected : 
	std::string _type;

public :
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal	operator=(const WrongAnimal &other);

	virtual void makeSound() const;
	virtual Brain *get_brain() const;
	std::string getType() const;
};

#endif