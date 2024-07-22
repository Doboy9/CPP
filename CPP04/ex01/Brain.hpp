/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:35:19 by dboire            #+#    #+#             */
/*   Updated: 2024/07/22 17:39:41 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Animal;

class Brain
{
private:

public:
	Brain();
	Brain(const Brain &other);
	Brain	operator=(const Brain &other);
	~Brain();

	std::string ideas[100];
};

#endif