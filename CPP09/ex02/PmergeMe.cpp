/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:53:21 by dboire            #+#    #+#             */
/*   Updated: 2024/11/11 13:51:44 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return *this;
}

template <typename Container>
void PmergeMe::printContainer(const Container &container)
{
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::parsing(std::string str)
{
	std::istringstream iss(str);
	std::vector<int> vec;
	std::deque<int> deq;
	double number;

	while (iss >> number)
	{
		if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		{
			std::cout << "Error" << std::endl;
			return;
		}
		vec.push_back(static_cast<int>(number));
		deq.push_back(static_cast<int>(number));
	}

	std::cout << "Before: ";
	printContainer(vec);

	// Measure time for vector
	clock_t start = clock();
	mergeInsertionSort(vec);
	clock_t end = clock();
	double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << elapsed << " us" << std::endl;

	// Measure time for deque
	start = clock();
	mergeInsertionSort(deq);
	end = clock();
	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << elapsed << " us" << std::endl;

	std::cout << "After: ";
	printContainer(deq);
}

void PmergeMe::mergeInsertionSort(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<int> mainGroup;
	std::vector<int> largerGroup;
	int lastElement;

	if (arr.size() % 2 != 0)
		lastElement = arr[arr.size() - 1];

	size_t limit;
	if (arr.size() % 2 != 0)
		limit = arr.size() - 1;
	else
		limit = arr.size();

	for (size_t i = 0; i < limit; i += 2)
	{
		int min = arr[i];
		int max = arr[i + 1];

		if (min > max)
		{
			int temp = min;
			min = max;
			max = temp;
		}
		mainGroup.push_back(min);
		largerGroup.push_back(max);
	}

	if (largerGroup.size() > 1)
		mergeInsertionSort(largerGroup);

	std::vector<int> result;
	result.push_back(mainGroup[0]);

	size_t jacobsthal = 1;
	size_t prevJacob = 1;

	for (size_t i = 0; i < largerGroup.size(); ++i)
	{
		int current = largerGroup[i];
		size_t left = 0;
		size_t right = result.size();

		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (result[mid] <= current)
				left = mid + 1;
			else
				right = mid;
		}
		result.insert(result.begin() + left, current);

		if (i + 1 < mainGroup.size())
		{
			current = mainGroup[i + 1];
			left = 0;
			right = result.size();
			while (left < right)
			{
				size_t mid = left + (right - left) / 2;
				if (result[mid] <= current)
					left = mid + 1;
				else
					right = mid;
			}
			result.insert(result.begin() + left, current);
		}

		if (i + 2 == jacobsthal)
		{
			size_t temp = jacobsthal;
			jacobsthal = jacobsthal + 2 * prevJacob;
			prevJacob = temp;
		}
	}

	if (arr.size() % 2 != 0)
	{
		size_t left = 0;
		size_t right = result.size();

		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (result[mid] <= lastElement)
				left = mid + 1;
			else
				right = mid;
		}
		result.insert(result.begin() + left, lastElement);
	}

	arr = result;
}

void PmergeMe::mergeInsertionSort(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::deque<int> mainGroup;
	std::deque<int> largerGroup;
	int lastElement;

	if (arr.size() % 2 != 0)
		lastElement = arr[arr.size() - 1];

	size_t limit;
	if (arr.size() % 2 != 0)
		limit = arr.size() - 1;
	else
		limit = arr.size();

	for (size_t i = 0; i < limit; i += 2)
	{
		int min = arr[i];
		int max = arr[i + 1];

		if (min > max)
		{
			int temp = min;
			min = max;
			max = temp;
		}
		mainGroup.push_back(min);
		largerGroup.push_back(max);
	}

	if (largerGroup.size() > 1)
		mergeInsertionSort(largerGroup);

	std::deque<int> result;
	result.push_back(mainGroup[0]);

	size_t jacobsthal = 1;
	size_t prevJacob = 1;

	for (size_t i = 0; i < largerGroup.size(); ++i)
	{
		int current = largerGroup[i];
		size_t left = 0;
		size_t right = result.size();

		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (result[mid] <= current)
				left = mid + 1;
			else
				right = mid;
		}
		result.insert(result.begin() + left, current);

		if (i + 1 < mainGroup.size())
		{
			current = mainGroup[i + 1];
			left = 0;
			right = result.size();
			while (left < right)
			{
				size_t mid = left + (right - left) / 2;
				if (result[mid] <= current)
					left = mid + 1;
				else
					right = mid;
			}
			result.insert(result.begin() + left, current);
		}

		if (i + 2 == jacobsthal)
		{
			size_t temp = jacobsthal;
			jacobsthal = jacobsthal + 2 * prevJacob;
			prevJacob = temp;
		}
	}

	if (arr.size() % 2 != 0)
	{
		size_t left = 0;
		size_t right = result.size();

		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (result[mid] <= lastElement)
				left = mid + 1;
			else
				right = mid;
		}
		result.insert(result.begin() + left, lastElement);
	}

	arr = result;
}