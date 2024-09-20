/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:05:00 by dboire            #+#    #+#             */
/*   Updated: 2024/09/14 14:05:00 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if(ac == 2)
	{
		std::ifstream input(av[1]);
		std::ifstream data("data.csv");
		if(input.is_open() && data.is_open())
		{
			BitcoinExchange Bitcoin;
			Bitcoin.parsing(data, input);
			Bitcoin.exec();
			input.close();
			data.close();
		}
		else
			std::cout << "Error: could not open file." << std::endl;
	}
	else
		std::cout << "Please enter only two arguments" << std::endl;
}