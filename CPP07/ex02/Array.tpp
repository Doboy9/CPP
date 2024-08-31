/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:11:32 by dboire            #+#    #+#             */
/*   Updated: 2024/08/31 18:18:53 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> // default constructor
Array<T>::Array() : data(NULL), size(0){};

template <typename T> // destructor
Array<T>::~Array()
{
	delete[] data;
}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), size(n){}; // Parameter constructor

template <typename T>
Array<T>::Array(const Array &other) : data(new T[other.size]()), size(other.size)
{
	for(unsigned int i = 0; i < size; i++)
		data[i] = other.data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	delete[] data;
	size = other.size;
	data = new T[size];
	for(unsigned int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if(index >= size)
	{
		throw(std::out_of_range("Index out of range"));
	}
	return(data[index]);
}