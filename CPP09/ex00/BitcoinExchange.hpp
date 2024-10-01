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
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange &src);
	BitcoinExchange(const BitcoinExchange& other);
	int parsing(std::ifstream &input, std::ifstream &data);
	void exec();

private:
	std::map<std::string, double> _input;
	std::map<std::string, double> _data;

	int mappinginput(std::ifstream &input);
	int mappingdata(std::ifstream &data);

	int splitdata(const std::string &line, std::string &date, double &value);
	int splitinput(const std::string &line, std::string &date, double &value);
};



#endif