/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:49:17 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:40:30 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Animal;
class Brain;

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

	Brain *get_brain() const;
	void makeSound() const;
};

#endif