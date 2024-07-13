/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:18 by dboire            #+#    #+#             */
/*   Updated: 2024/07/13 16:00:13 by dboire           ###   ########.fr       */
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
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	
	return 0;
}