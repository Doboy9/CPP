/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:08:45 by dboire            #+#    #+#             */
/*   Updated: 2024/10/02 15:19:05 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {};

Span::~Span(){};

void Span::addNumber(int number)
{
	if(_stock.size() >= static_cast<std::vector<int>::size_type>(_N))
		throw std::out_of_range("Span is full");
	_stock.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	 if (_stock.size() + std::distance(begin, end) > static_cast<std::vector<int>::size_type>(_N))
		throw std::out_of_range("Adding these numbers would exceed the span capacity");
	_stock.insert(_stock.end(), begin, end);
}

int Span::shortestSpan() const
{
	if(_stock.size() < 2)
		throw std::logic_error("Not enough numbers to find the shortest span");

	std::vector<int> sort = _stock;
	std::sort(sort.begin(), sort.end());
	
	int shortest = *(sort.begin() + 1) - *(sort.begin());
	for(std::vector<int>::size_type i = 0; i < sort.size() - 1; ++i)
	{
		int diff = sort[i + 1] - sort[i];
		if(diff < shortest)
			shortest = diff;
	}
	return(shortest);
}

int Span::longestSpan() const
{
	if(_stock.size() < 2)
		throw std::logic_error("Not enough numbers to find the shortest span");

	int min = *std::min_element(_stock.begin(), _stock.end());
	int max = *std::max_element(_stock.begin(), _stock.end());

	return(max - min);
}