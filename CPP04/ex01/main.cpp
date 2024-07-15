/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:18 by dboire            #+#    #+#             */
/*   Updated: 2024/07/14 15:41:29 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main()
{
	int		animal_nb = 4;
	Animal	*array[animal_nb];
	Brain	*cat_brain;
	Brain	*dog_brain;
	
	for (int i = 0; i < animal_nb; i++)
	{
		if(i < animal_nb / 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	
	cat_brain = array[0]->get_brain();
	dog_brain = array[2]->get_brain();
	cat_brain->ideas[0] = "Thinking";
	dog_brain->ideas[0] = "Dog thinking";
	// cat_brain->ideas[0] = array[0]->get_brain();
	// dog_brain->ideas[1] = array[3]->get_brain();
	
	std::cout << cat_brain->ideas[0] << std::endl;
	std::cout << dog_brain->ideas[0] << std::endl;
	
	return 0;
}