/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:53:21 by dboire            #+#    #+#             */
/*   Updated: 2024/10/19 17:22:36 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

template <typename Container>
void PmergeMe::printContainer(const Container& container) {
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
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

	while(iss >> number)
	{
		if(number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		{
			std::cout << "Error" << std::endl;
			return ;
		}
		vec.push_back(static_cast<int>(number));
		deq.push_back(static_cast<int>(number));
	}
	exec(vec);
	exec(deq);
}

template<typename Container>
void PmergeMe::exec(Container& container)
{
	Container smaller;

	MinMax* head = 0;
	MinMax* tail = 0;
	for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
	{
		MinMax* newNode = new MinMax;
		newNode->min = *it;
		newNode->max = 0;
		newNode->next = 0;
		if (!head)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	MinMax* current = head;
	while (current)
	{
		smaller.push_back(current->min);
		current = current->next;
	}
	
	// std::cout << "Before: ";
	// printContainer(smaller);
	
	
	clock_t start = clock();
	
	if(smaller.size() > 1)
		mergeInsertionSort(smaller);
	
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e3; // Convert to microseconds
	
	// std::cout << "After: ";
	// printContainer(smaller);
	std::string typeName = typeid(container).name();
	if(typeName.find("vector") != std::string::npos)
		std::cout << "Time to process a range of " << smaller.size() << " elements with std::vector : " << duration << " us" << std::endl;
	else if(typeName.find("deque") != std::string::npos)
		std::cout << "Time to process a range of " << smaller.size() << " elements with std::deque : " << duration << " us" << std::endl;
}

template <typename Container>
void PmergeMe::mergeInsertionSort(Container& container)
{
	if (container.size() <= 10)
	{
		insertionSort(container);
		return;
	}

	typename Container::iterator middle = container.begin() + container.size() / 2;
	Container left(container.begin(), middle);
	Container right(middle, container.end());

	mergeInsertionSort(left);
	mergeInsertionSort(right);

	merge(left, right, container);
}

template <typename Container>
void PmergeMe::merge(Container& left, Container& right, Container& result)
{
	typename Container::iterator itLeft = left.begin();
	typename Container::iterator itRight = right.begin();
	typename Container::iterator itResult = result.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft <= *itRight) {
			*itResult = *itLeft;
			++itLeft;
		} else {
			*itResult = *itRight;
			++itRight;
		}
		++itResult;
	}

	while (itLeft != left.end())
	{
		*itResult = *itLeft;
		++itLeft;
		++itResult;
	}

	while (itRight != right.end())
	{
		*itResult = *itRight;
		++itRight;
		++itResult;
	}
}

template <typename Container>
Container PmergeMe::generateJacobsthalSequence(int size, Container &container)
{
	(void)container;
	Container jacobsthal;
	int j0 = 0, j1 = 1;
	jacobsthal.push_back(j0);
	if (size > 1)
		jacobsthal.push_back(j1);
	while (true)
	{
		int jn = j1 + 2 * j0; // next Jacobsthal number
		if (jn >= size) 
			break; // exits the loop if the new number exceeds the specified size. (My container size)
		jacobsthal.push_back(jn); // adds the number to the container
		j0 = j1;
		j1 = jn;
	}
	return jacobsthal;
}

template <typename Container>
void PmergeMe::insertionSort(Container& container)
{
	Container jacobsthal = generateJacobsthalSequence(container.size(), container);

	for (typename Container::iterator gapIt = jacobsthal.begin(); gapIt != jacobsthal.end(); ++gapIt)
	{
		int gap = *gapIt;
		for (typename Container::iterator it = container.begin() + gap; it != container.end(); ++it)
		{
			typename Container::iterator jt = it;
			typename Container::iterator prev = it - gap;
			while (jt >= container.begin() + gap && *jt < *prev)
			{
				std::swap(*jt, *prev);
				jt -= gap;
				prev -= gap;
			}
		}
	}
}