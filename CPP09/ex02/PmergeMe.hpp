/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:53:23 by dboire            #+#    #+#             */
/*   Updated: 2024/10/01 17:10:47 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>

struct MinMax
{
	int min;
	int max;
	MinMax* next;
};


class PmergeMe
{
private:
	template<typename Container>
	void exec(Container& container);

	template<typename Container>
	void mergeInsertionSort(Container& container);

	template<typename Container>
	void printContainer(const Container& container);
	
	template<typename Container>
	void merge(Container& left, Container& right, Container& result);
	
	template <typename Container>
	void insertionSort(Container& container);
	
	template <typename Container>
	Container generateJacobsthalSequence(int size, Container &container);
	
	std::deque<int> deq;
	std::vector<int> vec;
	MinMax* head;

public:
	PmergeMe();
	~PmergeMe();
	void parsing(std::string str);
};

#endif