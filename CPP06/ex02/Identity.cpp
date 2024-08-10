/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:24:31 by dboire            #+#    #+#             */
/*   Updated: 2024/08/10 10:09:26 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identity.hpp"

Base::~Base(){};
A::A(){};
B::B(){};
C::C(){};
A::~A(){};
B::~B(){};
C::~C(){};


Base* generate(void)
{
	std::srand(time(NULL));
	int random = (std::rand() % 3);
	if(random == 0)
		return new A();
	if(random == 1)
		return new B();
	if(random == 2)
		return new C();
	return NULL;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
	return ;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (...) {}

	return ;
}