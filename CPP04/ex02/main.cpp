/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:18 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:58:03 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{

	int		animal_nb = 4;
	Animal	*array[animal_nb];
	Brain	*cat_brain[animal_nb / 2];
	Brain	*dog_brain[animal_nb / 2];
	// WrongAnimal	*wrong_array[2];
	// Brain	*wrongcat_brain[2];
	
	for (int i = 0; i < animal_nb; i++)
	{
		if(i < animal_nb / 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	// wrong_array[0] = new WrongCat();
	// wrong_array[1] = new WrongCat();
	
	
	Dog basic;
	{
		Dog tmp = basic;
	}
	
	// wrongcat_brain[0] = wrong_array[0]->get_brain();
	
	cat_brain[0] = array[0]->get_brain();
	cat_brain[1] = array[1]->get_brain();
	dog_brain[0] = array[2]->get_brain();
	dog_brain[1] = array[3]->get_brain();
	
	// wrongcat_brain[0]->ideas[0] = "WrongCat 1 is Thinking";
	cat_brain[0]->ideas[0] = "Cat 1 is Thinking";
	dog_brain[0]->ideas[0] = "Dog 1 is thinking";
	cat_brain[0]->ideas[1] = "Cat 1 is Thinking 2";
	dog_brain[0]->ideas[1] = "Dog 1 is Thinking 2";
	cat_brain[1]->ideas[0] = "Cat 2 is Thinking";
	dog_brain[1]->ideas[0] = "Dog 2 is thinking";
	
	// std::cout << wrongcat_brain[0]->ideas[0] << std::endl;
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