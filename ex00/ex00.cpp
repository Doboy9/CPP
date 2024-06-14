/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:11:52 by dboire            #+#    #+#             */
/*   Updated: 2024/06/14 14:11:52 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
			std::string str;
		for (int i = 1; i < argc; i++)
			str += argv[i];
		for(int j = 0; j < str.length(); j++)
				std::cout << (char)toupper(str[j]);
		std:: cout << std::endl ;
	}
	return (0);
}