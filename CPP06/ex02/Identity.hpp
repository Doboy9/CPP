/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:24:45 by dboire            #+#    #+#             */
/*   Updated: 2024/08/10 10:07:48 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTITY_HPP
# define IDENTITY_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
private:

public:
	virtual ~Base();
};

class A : public Base
{
private:

public:
	A();
	~A();
};

class B : public Base
{
private:

public:
	B();
	~B();
};

class C : public Base
{
private:

public:
	C();
	~C();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);


#endif