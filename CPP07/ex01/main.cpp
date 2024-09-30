/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:42:55 by dboire            #+#    #+#             */
/*   Updated: 2024/09/30 10:38:01 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	char arr2[] = {'a', 'b', 'c', 'd'};
	int length = sizeof(arr) / sizeof(arr[0]);
	int length2 = sizeof(arr2) / sizeof(arr2[0]);

	std::cout << "Original array: ";
	iter(arr, length, printT);
	std::cout << std::endl;

	iter(arr, length, increment);

	std::cout << "Incremented array: ";
	iter(arr, length, printT);
	std::cout << std::endl;
	
	std::cout << "Original array: ";
	iter(arr2, length2, printT);
	std::cout << std::endl;

	iter(arr2, length2, increment);

	std::cout << "Incremented array: ";
	iter(arr2, length2, printT);
	std::cout << std::endl;

	return 0;
}