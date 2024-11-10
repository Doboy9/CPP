/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:50:17 by dboire            #+#    #+#             */
/*   Updated: 2024/10/02 15:09:42 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		int found = easyfind(vec, 3);
		std::cout << "Found: " << found << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		int found = easyfind(vec, 6);
		std::cout << "Found: " << found << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}