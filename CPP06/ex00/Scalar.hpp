/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:32:39 by dboire            #+#    #+#             */
/*   Updated: 2024/08/02 14:32:39 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
public:

	static void convert(const std::string &arg);

};





#endif