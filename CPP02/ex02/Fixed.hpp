/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:24 by dboire            #+#    #+#             */
/*   Updated: 2024/07/07 16:29:13 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:

    int _stock;
    static const int _Bits = 8;

public:

    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed   operator=(const Fixed &other);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void)const;
    int     toInt(void)const;
    friend std::ostream &operator<<(std::ostream &out, const Fixed &value);
    
    bool    operator>(const Fixed &other) const;
    bool    operator<(const Fixed &other) const;
    bool    operator>=(const Fixed &other) const;
    bool    operator<=(const Fixed &other) const;
    bool    operator==(const Fixed &other) const;
    bool    operator!=(const Fixed &other) const;
    
    Fixed operator+(const Fixed& other);
    Fixed operator-(const Fixed& other);
    Fixed operator*(const Fixed& other);
    Fixed operator/(const Fixed& other);
    
    Fixed operator++(int);
    Fixed operator++();
    Fixed operator--(int);
    Fixed operator--();

    Fixed const	&Fixed::min(Fixed const &a, Fixed const &b);
    Fixed const	&Fixed::max(Fixed const &a, Fixed const &b);
    Fixed const	&Fixed::min(Fixed &a, Fixed &b);
    Fixed const	&Fixed::max(Fixed &a, Fixed &b);
};




#endif