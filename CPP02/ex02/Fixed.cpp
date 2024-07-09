/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:20 by dboire            #+#    #+#             */
/*   Updated: 2024/07/09 15:42:58 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_stock(0){};

Fixed::~Fixed(){};

Fixed::Fixed(const Fixed &other)
{
	this->_stock = other._stock;
}

Fixed Fixed::operator=(const Fixed &other)
{
	if(this != &other)
	{
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

int	Fixed::getRawBits(void)const
{
	return (_stock);
}

void	Fixed::setRawBits(int raw)
{
	_stock = raw;
}

Fixed::Fixed(const int num)
{
	_stock = num << _Bits;
}

Fixed::Fixed(const float num)
{
	_stock = static_cast<int>(num * (1 << _Bits));
}

float   Fixed::toFloat() const
{
	return (static_cast<float>(_stock) / (1 << _Bits));
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

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}