/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:53:23 by dboire            #+#    #+#             */
/*   Updated: 2024/11/11 13:17:35 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <ctime>
#include <typeinfo>

struct MinMax
{
	int min;
	int max;
	MinMax *next;
};

class PmergeMe
{
private:
	template <typename Container>
	void printContainer(const Container &container);

	void mergeInsertionSort(std::vector<int> &arr);
	void mergeInsertionSort(std::deque<int> &arr);

	std::deque<int> deq;
	std::vector<int> vec;
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &src);

public:
	PmergeMe();
	~PmergeMe();
	void parsing(std::string str);
};

#endif