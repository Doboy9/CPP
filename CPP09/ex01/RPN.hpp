/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:10:17 by dboire            #+#    #+#             */
/*   Updated: 2024/11/11 13:36:35 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <cctype>
#include <sstream>

class RPN
{
private:
	std::list<int> _number_list;
	std::list<char> _operator_list;
	std::list<std::string> _tokens;
	void exec();
	RPN(const RPN &other);
	RPN &operator=(const RPN &src);

public:
	RPN();
	~RPN();
	void parsing(const std::string &av);
};

#endif