/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:49:47 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:57:46 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal {
private : 
	virtual void makeSound() const;
protected : 
	std::string _type;
	std::string _name;

public :
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal	operator=(const WrongAnimal &other);
	std::string getType() const;
};

#endif