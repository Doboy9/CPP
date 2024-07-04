/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:24 by dboire            #+#    #+#             */
/*   Updated: 2024/07/04 09:30:24 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:

    int _stock;
    static const int _Bits = 8;

public:

    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed   &operator=(const Fixed &other);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void)const;
    int     toInt(void)const;
    friend std::ostream &operator<<(std::ostream &out, const Fixed &value);
};




#endif