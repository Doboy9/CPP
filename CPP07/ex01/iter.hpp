/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:42:51 by dboire            #+#    #+#             */
/*   Updated: 2024/08/10 16:36:20 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP


template <typename T>
void iter(T *Array, int len_Array, void (*function)(T&))
{
	for(int i = 0; i < len_Array; i++)
		function(Array[i]);
}

template <typename T>
void printT(T& x) 
{
	std::cout << x << " ";
}

template <typename T>
void increment(T& x) 
{
	++x;
}

#endif