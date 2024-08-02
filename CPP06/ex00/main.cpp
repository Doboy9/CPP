/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:44:53 by dboire            #+#    #+#             */
/*   Updated: 2024/08/02 14:44:53 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main() 
{
    std::string numStr = "65"; // ASCII value for 'A'
    ScalarConverter::convert(numStr);
    return 0;
}