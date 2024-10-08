/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:34:22 by dboire            #+#    #+#             */
/*   Updated: 2024/09/06 13:38:31 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
	Data data;
	uintptr_t raw;
	Data* deserialized;
	
	data.num = 10000000;
	
	raw = Serializer::serialize(&data);
	std::cout << "Serialized value: " << raw << std::endl;
	
	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized value: " << deserialized << std::endl;
	std::cout << "Deserialized data.num: " << deserialized->num << std::endl;

	if (deserialized->num == data.num)
		std::cout << "Deserialization successful!" << std::endl;
	else
		std::cout << "Deserialization failed!" << std::endl;
}