/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:29:10 by dboire            #+#    #+#             */
/*   Updated: 2024/08/10 15:41:34 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T c;
	
	c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T a, T b)
{
	if ( a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}