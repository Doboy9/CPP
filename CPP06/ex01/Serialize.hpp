/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:06:04 by dboire            #+#    #+#             */
/*   Updated: 2024/08/08 10:31:00 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include<iostream>
#include<stdint.h>

struct Data
{
	int num;
};

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer&);
	Serializer &operator=(const Serializer&);

public:
	static uintptr_t serialize(Data* ptr);

	static Data* deserialize(uintptr_t raw);

};



#endif