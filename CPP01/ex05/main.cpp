/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:22:46 by dboire            #+#    #+#             */
/*   Updated: 2024/06/30 16:07:56 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{

	Harl Harl;

	std::cout << "Harl error : ";
	Harl.complain("ERROR");
	std::cout << std::endl;
	
	std::cout << "Harl warning : ";
	Harl.complain("WARNING");
	std::cout << std::endl;
	
	std::cout << "Harl info : ";
	Harl.complain("INFO");
	std::cout << std::endl;
	
	std::cout << "Harl debug : ";
	Harl.complain("DEBUG");
	std::cout << std::endl;
	
	std::cout << "Harl not found : ";
	Harl.complain("??????");
	std::cout << std::endl;

	return (0);
}