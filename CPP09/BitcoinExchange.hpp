/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:03:49 by dboire            #+#    #+#             */
/*   Updated: 2024/09/14 14:03:49 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

#include<iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange &src);
	BitcoinExchange(const BitcoinExchange& other);
	int parsing(std::ifstream &input, std::ifstream &data);

private:
	std::map<std::string, int> _input;
	std::map<std::string, int> _data;
	int parsinginput(std::ifstream &input);
	int parsingdata(std::ifstream &data);
	void splitLine(const std::string &line, std::string &date, double &value);
	void exec(std::ifstream &file);
};



#endif