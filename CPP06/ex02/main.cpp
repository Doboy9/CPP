/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:24:42 by dboire            #+#    #+#             */
/*   Updated: 2024/09/06 14:24:57 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identity.hpp"
#include <unistd.h>

int main(void)
{
	Base* base1;
	base1 = generate();

	identify(*base1);
	identify(base1);

	sleep(1);
	Base* base2;
	base2 = generate();

	identify(*base2);
	identify(base2);

	sleep(1);
	Base* base3;
	base3 = generate();

	identify(*base3);
	identify(base3);
}