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
	mappinginput(input);
	mappingdata(data);
	return(0);
}

int BitcoinExchange::mappinginput(std::ifstream &input)
{
	std::string line;
	while (std::getline(input, line)) 
	{
		std::string date;
		double value;
		splitinput(line, date, value);
		_input[date] = value;
    }
	return (0);
}

int BitcoinExchange::mappingdata(std::ifstream &data)
{
	std::string line;
	while (std::getline(data, line)) 
	{
		std::string date;
		double value;
		splitdata(line, date, value);
		_data[date] = value;
    }
	return (0);
}

int BitcoinExchange::splitdata(const std::string &line, std::string &date, double &value) 
{
	if(line.find_first_not_of("0123456789-,. ") != std::string::npos)
		std::cout << "Line not valid: " << line << std::endl;
	std::string::size_type pos = line.find(',');
	if (pos != std::string::npos)
	{
		date = line.substr(0, pos);
		if(date.length() != 10)
			std::cout << "Date not valid: " << line << std::endl;
		std::string valueStr = line.substr(pos + 1);
		std::stringstream ss(valueStr);
        ss >> value;
        if (ss.fail())
			std::cout << "Invalid line format: " << line << std::endl;
	}
	else 
		std::cerr << "Error: invalid line format data: " << line << std::endl;
	return (0);
}

int BitcoinExchange::splitinput(const std::string &line, std::string &date, double &value) 
{
	if(line.find_first_not_of("0123456789-|.,\r ") != std::string::npos)
		std::cout << "Line not valid: " << line << std::endl;
	std::string::size_type pos = line.find('|');
	if (pos != std::string::npos)
	{
		date = line.substr(0, pos - 1);
		if(date.find_first_not_of("0123456789- ") != std::string::npos)
			std::cout << "Date not valid: " << line << std::endl;
		std::string valueStr = line.substr(pos + 1);
		std::stringstream ss(valueStr);
        ss >> value;
        if (ss.fail())
			std::cout << "Invalid line format: " << line << std::endl;
		if(value < 0)
			std::cout << "Error: not a positive number." << std::endl;
	}
	else 
		std::cerr << "Error: invalid line format data: " << line << std::endl;
	return (0);
}

void BitcoinExchange::exec()
{
	for(std::map<std::string, double>::iterator it = _input.begin(); it != _input.end(); ++it)
	{
		std::map<std::string, double>::iterator itdata = _data.upper_bound(it->first);
		if (itdata != _data.begin() && (itdata == _data.end() || itdata->first > it->first))
        {
            --itdata;
        }
		if(itdata != _data.end())
			std::cout << it->first << " => " << it->second << " = " << itdata->second * it->second << std::endl;
		else
			std::cout << "Date not found: " << it->first << ", Input Value: " << it->second << ", Data Value: " << itdata->second   << std::endl;
	}
}