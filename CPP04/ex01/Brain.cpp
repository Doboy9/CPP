/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:35:25 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:36:10 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"
#include"Brain.hpp"

Brain::Brain() : ideas()
{
	std::cout << "Default constructor of Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Default destructor of Brain" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
}

Brain Brain::operator=(const Brain &other)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}