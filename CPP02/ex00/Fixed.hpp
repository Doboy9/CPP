/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:24 by dboire            #+#    #+#             */
/*   Updated: 2024/07/03 16:43:31 by dboire           ###   ########.fr       */
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
    Fixed &operator=(const Fixed &other);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};




#endif