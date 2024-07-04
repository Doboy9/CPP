/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:20 by dboire            #+#    #+#             */
/*   Updated: 2024/07/04 09:38:21 by dboire           ###   ########.fr       */
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
    _stock = static_cast<int>(num * (1 << _Bits));
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

float   Fixed::toFloat() const
{
    return static_cast<float>(_stock) / (1 << _Bits);
}

int   Fixed::toInt() const
{
    return (_stock >> _Bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return(out);
}