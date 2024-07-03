/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:20 by dboire            #+#    #+#             */
/*   Updated: 2024/07/03 17:46:38 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_stock(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    _stock = num << _Bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Int constructor called" << std::endl;
    _stock = num << _Bits;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other):_stock(other._stock)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        setRawBits(other._stock);
    }
    return (*this);
}
int     Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _stock;
}
void    Fixed::setRawBits(int const raw)
{
    std::cout << "getRawBits member function called" << std::endl;
    _stock = raw;
}