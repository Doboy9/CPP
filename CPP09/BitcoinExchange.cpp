/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:04:36 by dboire            #+#    #+#             */
/*   Updated: 2024/09/14 14:04:36 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::~BitcoinExchange(){};

int BitcoinExchange::parsing(std::ifstream &data, std::ifstream &input)
{
	parsinginput(input);
	parsingdata(data);
	return(0);
}

int BitcoinExchange::parsinginput(std::ifstream &input)
{
	std::string line;
	while (std::getline(input, line)) 
	{
		std::string date;
		double value;
		splitLine(line, date, value);
		_input[date] = value;
    }
}

int BitcoinExchange::parsingdata(std::ifstream &data)
{
	std::string line;
	while (std::getline(data, line)) 
	{
		std::string date;
		double value;
		splitLine(line, date, value);
		_data[date] = value;
    }
}

void BitcoinExchange::splitLine(const std::string &line, std::string &date, double &value) 
{
	std::string::size_type pos = line.find('|');
	if (pos != std::string::npos)
	{
		date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 1);
		value = std::atof(valueStr.c_str());
	} 
	else 
		std::cerr << "Error: invalid line format: " << line << std::endl;
}