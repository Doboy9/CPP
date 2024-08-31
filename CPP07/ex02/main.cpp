/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:11:40 by dboire            #+#    #+#             */
/*   Updated: 2024/08/31 18:21:08 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> intArray(5);

	for (unsigned int i = 0; i < 5; ++i) {
		intArray[i] = i * 10;
	}

	for (unsigned int i = 0; i < 5; ++i) {
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}

	Array<double> doubleArray(3);

	for (unsigned int i = 0; i < 3; ++i) {
		doubleArray[i] = i * 1.5; 
	}


	for (unsigned int i = 0; i < 3; ++i) {
		std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
	}

	Array<int> copyArray = intArray;

	for (unsigned int i = 0; i < 5; ++i) {
		std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
	}
	
	Array<char> charArray(5);

	for (unsigned int i = 0; i < 5; ++i) {
		charArray[i] = 'A' + i; 
	}

	for (unsigned int i = 0; i < 5; ++i) {
		std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
	}

	return 0;
}