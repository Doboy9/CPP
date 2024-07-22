/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:49:17 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 16:50:46 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Animal;

class Cat : public Animal
{
private: 

public:
	Cat();
	Cat(std::string const &type);
	Cat(const Cat &other);
	Cat	operator=(const Cat &other);
	~Cat();
	
	void makeSound() const;
};

#endif