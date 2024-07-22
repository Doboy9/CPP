/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:50:32 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:53:37 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongAnimal;

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

#endif