/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:50:32 by dboire            #+#    #+#             */
/*   Updated: 2024/07/23 12:17:58 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongAnimal;
class Brain;

class WrongCat : public WrongAnimal
{
private: 
	Brain *brain;

public:
	WrongCat();
	WrongCat(std::string const &type);
	WrongCat(const WrongCat &other);
	WrongCat	operator=(const WrongCat &other);
	~WrongCat();

	Brain *get_brain() const;
	void makeSound() const;
};

#endif