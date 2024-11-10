/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:10:17 by dboire            #+#    #+#             */
/*   Updated: 2024/10/20 17:48:57 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <list>
#include <cctype>

class RPN
{
private:
	std::list<int>		_number_list;
	std::list<char>	_operator_list;
	void exec();
public:
	RPN();
	~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN &src);
	void parsing(std::string av);
};




#endif