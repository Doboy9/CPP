/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:44:19 by dboire            #+#    #+#             */
/*   Updated: 2024/08/31 18:52:59 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int easyfind(T & container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if(it == container.end())
		throw std::runtime_error("Value not found");
	return (*it);
}