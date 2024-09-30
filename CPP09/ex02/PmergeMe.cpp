/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:53:21 by dboire            #+#    #+#             */
/*   Updated: 2024/09/30 14:11:08 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe()
{
	// MinMax* current = head;
	// while (current != NULL)
	// {
	// 	MinMax* next = current->next;
	// 	delete current;
	// 	current = next;
	// }
}

void PmergeMe::parsing(std::string str)
{
	std::istringstream iss(str);
	std::vector<int> vec_tmp;
	double number;

	while(iss >> number)
	{
		if(number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		{
			std::cout << "Error" << std::endl;
			return ;
		}
		vec_tmp.push_back(static_cast<int>(number));
	}
	std::cout << "Vector contents: ";
	for (std::vector<int>::const_iterator it = vec_tmp.begin(); it != vec_tmp.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	exec();
}

void PmergeMe::execdeq()
{
	MinMax* current = NULL;
	MinMax* prev = NULL;

	for(size_t i = 0; i < deq.size(); i += 2)
	{
		MinMax* node = new MinMax();
		node->min = deq[i];
		
		if (i + 1 < deq.size())
			node->max = deq[i + 1];
		else
			node->max = NULL;
		
		node->next = NULL;
		node->prev = prev;
		
		if (prev != NULL)
			prev->next = node;
		else
			head = node;
		
		prev = node;
	}
	recursive_exec(head);
}

void PmergeMe::execvec()
{
	for(size_t i = 0; i < vec.size(); i += 2)
	{
		MinMax* node = new MinMax();
		node->min = deq[i];

		if (i + 1 < vec.size())
			node->max = deq[i + 1];
		else
			node->max = NULL;

		node->next = NULL;
		node->prev = prev;
		
		if (prev != NULL)
			prev->next = node;
		else
			head = node;

		prev = node;
	}
	
	recursive_exec(head);
}

void PmergeMe::recursive_exec(MinMax* head)
{
	if(!head)
		return ;

	MinMax* current = head;

	while(current)
	{
		if(current->max != NULL)
		{
			if(current->min > current->max)
				std::swap(current->min, current->max);

			larger.push_back(current->max);
			smaller.push_back(current->min);
		}
		else
			smaller.push_back(current->min);
		
		current = current->next;
	}
	recursive_exec(larger)

}