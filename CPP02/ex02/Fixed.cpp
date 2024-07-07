/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:20 by dboire            #+#    #+#             */
/*   Updated: 2024/07/07 16:31:00 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_stock(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
}

Fixed Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        setRawBits(other.getRawBits());
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

bool    Fixed::operator>(const Fixed &other) const
{
    if(this->_stock > other.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<(const Fixed &other) const
{
    if(this->_stock < other.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator>=(const Fixed &other) const
{
    if(this->_stock >= other.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<=(const Fixed &other) const
{
    if(this->_stock <= other.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator==(const Fixed &other) const
{
    if(this->_stock == other.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator!=(const Fixed &other) const
{
    if(this->_stock != other.getRawBits())
        return (true);
    return (false);
}

Fixed   Fixed::operator+(const Fixed& other)
{
    this->_stock += other.getRawBits();
    return (*this);
}

Fixed   Fixed::operator-(const Fixed& other)
{
    this->_stock -= other.getRawBits();
    return (*this);
}

Fixed   Fixed::operator*(const Fixed& other)
{
    this->_stock = (this->toFloat() * other.toFloat()) * (1 << _Bits);
    return (*this);
}

Fixed   Fixed::operator/(const Fixed& other)
{
    this->_stock = (this->toFloat() / other.toFloat()) * (1 << _Bits);
    return (*this);
}

Fixed   Fixed::operator++()
{
    this->_stock++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed before = *this;
    ++_stock;
    return (before);
}

Fixed   Fixed::operator--()
{
    this->_stock--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed before = *this;
    --_stock;
    return (before);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed const	&Fixed::min(Fixed &a, Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed const	&Fixed::max(Fixed &a, Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}