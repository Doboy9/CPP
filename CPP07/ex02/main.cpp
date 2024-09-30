/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:11:40 by dboire            #+#    #+#             */
/*   Updated: 2024/09/30 10:47:24 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 200
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++){
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++){
		std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}




// int main() {
// 	Array<int> intArray(5);

// 	for (unsigned int i = 0; i < 5; ++i) {
// 		intArray[i] = i * 10;
// 	}

// 	for (unsigned int i = 0; i < 5; ++i) {
// 		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
// 	}

// 	Array<double> doubleArray(3);

// 	for (unsigned int i = 0; i < 3; ++i) {
// 		doubleArray[i] = i * 1.5; 
// 	}


// 	for (unsigned int i = 0; i < 3; ++i) {
// 		std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
// 	}

// 	Array<int> copyArray = intArray;

// 	for (unsigned int i = 0; i < 5; ++i) {
// 		std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
// 	}
	
// 	Array<char> charArray(5);

// 	for (unsigned int i = 0; i < 5; ++i) {
// 		charArray[i] = 'A' + i; 
// 	}

// 	for (unsigned int i = 0; i < 5; ++i) {
// 		std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
// 	}

// 	return 0;
// }