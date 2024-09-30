/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:53:23 by dboire            #+#    #+#             */
/*   Updated: 2024/09/30 10:04:07 by dboire           ###   ########.fr       */
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

struct MinMax
{
	int min;
	int max;
	MinMax* next;
	MinMax* prev;
};


class PmergeMe
{
private:
	void execdeq();
	void execvec();
	void recursive_exec(MinMax *head);
	std::deque<int> deq;
	std::vector<int> vec;
	MinMax* head;

public:
	PmergeMe();
	~PmergeMe();
	void parsing(std::string str);
};

#endif