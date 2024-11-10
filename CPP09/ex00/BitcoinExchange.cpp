/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:04:36 by dboire            #+#    #+#             */
/*   Updated: 2024/10/20 16:05:31 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange&){};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &)
{
    return *this;
}

int BitcoinExchange::parsing(std::ifstream &data, std::ifstream &input)
{
	mappinginput(input);
	mappingdata(data);
	return(0);
}

int BitcoinExchange::mappinginput(std::ifstream &input)
{
	int i = 0;
	std::string line;
	while (std::getline(input, line)) 
	{
		if(i == 0 && line == "date | value")
			continue;
		std::string date;
		double value = 0;
		splitinput(line, date, value);
		_input[date] = value;
    }
	return (0);
}

int BitcoinExchange::mappingdata(std::ifstream &data)
{
	int i = 0;
	std::string line;
	while (std::getline(data, line)) 
	{
		if(i == 0 && line == "date,exchange_rate")
			continue;
		std::string date;
		double value = 0;
		splitdata(line, date, value);
		_data[date] = value;
		i++;
    }
	return (0);
}

bool isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	std::istringstream yearStream(date.substr(0, 4));
	std::istringstream monthStream(date.substr(5, 2));
	std::istringstream dayStream(date.substr(8, 2));

	if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
		return false;

	if (month < 1 || month > 12 || year < 2009)
		return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
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

void BitcoinExchange::splitinput(const std::string &line, std::string &date, double &value) 
{
	std::string::size_type pos = line.find('|');
	if(line.find_first_not_of("0123456789-|.,\r ") != std::string::npos)
		std::cout << "Line not valid: " << line << std::endl;
	else if (pos != std::string::npos)
	{
		date = line.substr(0, pos - 1);
		if(!isValidDate(date))
		{
			std::cout << "Date not valid: " << line << std::endl;
			return ;
		}
		std::string valueStr = line.substr(pos + 1);
		std::stringstream ss(valueStr);
		ss >> value;
		if (ss.fail())
			std::cout << "Invalid line format: " << line << std::endl;
		if(value < 0 || value > 1000)
		{
			std::cout << "Error: number need to be between 0 and 1000." << std::endl;
			value = -1;
		}
	}
	else 
		std::cerr << "Error: invalid line format data: " << line << std::endl;
	return ;
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
		if(itdata != _data.end() && !it->first.empty() && it->second && it->second > 0)
			std::cout << it->first << " => " << it->second << " = " << itdata->second * it->second << std::endl;
	}
}