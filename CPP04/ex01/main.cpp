/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:18 by dboire            #+#    #+#             */
/*   Updated: 2024/07/15 11:16:10 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main()
{
	int		animal_nb = 4;
	Animal	*array[animal_nb];
	Brain	*cat_brain[2];
	Brain	*dog_brain[2];
	
	for (int i = 0; i < animal_nb; i++)
	{
		if(i < animal_nb / 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	
	cat_brain[0] = array[0]->get_brain();
	cat_brain[1] = array[1]->get_brain();
	dog_brain[0] = array[2]->get_brain();
	dog_brain[1] = array[3]->get_brain();
	cat_brain[0]->ideas[0] = "Cat 1 is Thinking";
	dog_brain[0]->ideas[0] = "Dog 1 is thinking";
	cat_brain[0]->ideas[1] = "Cat 1 is Thinking 2";
	dog_brain[0]->ideas[1] = "Dog 1 is Thinking 2";
	cat_brain[1]->ideas[0] = "Cat 2 is Thinking";
	dog_brain[1]->ideas[0] = "Dog 2 is thinking";
	
	std::cout << cat_brain[0]->ideas[0] << std::endl;
	std::cout << dog_brain[0]->ideas[0] << std::endl;
	std::cout << cat_brain[0]->ideas[1] << std::endl;
	std::cout << dog_brain[0]->ideas[1] << std::endl;
	std::cout << cat_brain[1]->ideas[0] << std::endl;
	std::cout << dog_brain[1]->ideas[0] << std::endl;
	
	delete array[0];
	delete array[1];
	delete array[2];
	delete array[3];
	return 0;
}