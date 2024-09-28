/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:39:28 by dboire            #+#    #+#             */
/*   Updated: 2024/09/28 11:06:07 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include<iostream>
#include<list>
#include<stack>
#include<deque>
#include<iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack<T>& other);
	MutantStack<T>& operator=(const MutantStack<T>& other);

	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();
};


#endif