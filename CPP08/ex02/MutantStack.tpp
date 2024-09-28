/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:39:24 by dboire            #+#    #+#             */
/*   Updated: 2024/09/28 11:04:47 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){};

template <typename T>
MutantStack<T>::~MutantStack(){};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if(this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}