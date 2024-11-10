/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:08:59 by dboire            #+#    #+#             */
/*   Updated: 2024/10/02 15:19:15 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(15000);
	try
	{
		std::vector<int> numbers(15000);
		std::srand(std::time(0));
		
		for (int i = 0; i < 15000; ++i)
		{
			numbers[i] = std::rand() % 15000 + 1; // Generate random numbers between 1 and 15000
		}
		sp.addNumbers(numbers.begin(), numbers.end());
	}
	catch (const std::out_of_range& e){
		std::cerr << "Exception: " << e.what() << std::endl;}
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::logic_error& e){
		std::cerr << "Exception: " << e.what() << std::endl;}
		
	Span sp2 = Span(5);
	try
	{
		sp2.addNumber(6);
		sp2.addNumber(3);
		sp2.addNumber(17);
		sp2.addNumber(9);
		sp2.addNumber(11);
	}
	catch (const std::out_of_range& e){
		std::cerr << "Exception: " << e.what() << std::endl;}
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::logic_error& e){
		std::cerr << "Exception: " << e.what() << std::endl;}
	return 0;
}