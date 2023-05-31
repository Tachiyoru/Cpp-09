/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:57:25 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 11:45:47 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::cout<<"BitcoinExchange constructor called"<<std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &toCopy){
	if (this != &toCopy)
		*this = toCopy;
	std::cout<<"BitcoinExchange copy constructor called"<<std::endl;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout<<"BitcoinExchange destructor called"<<std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &toCopy){
	_dataMap.insert(toCopy._dataMap.begin(), toCopy._dataMap.end());
	return (*this);
}

void	BitcoinExchange::storeInfile(){
	std::ifstream file("data.csv");
	if (!file){
		std::cerr << "Error form opening the csv file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)){
		std::istringstream iss(line);
		std::string date;
		float value;

		std::getline(iss, date, ',');
		iss >> value;
		if (date.empty()){
			std::cerr << "Error : Could not parse this line : " << line << std::endl;
			continue;
		}
		if (iss.fail()){
			std::cerr << "Error : Could not parse this line : " << line << std::endl;
			continue;
		}
		this->_dataMap[date] = value;
	}
	file.close();
	return ;
}

void	BitcoinExchange::display(char *infile){
	std::ifstream file(infile);
	if (!file){
		std::cerr << "Error : could not open the file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)){
		std::istringstream	iss(line);
		std::string			date;
		std::string			sep;
		float				value;
		float				trueValue = 0.0;

		if (!(iss >> date >> sep >> value)){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		else if (parseValue(value))
			;
		else if (parseDate(date))
			std::cerr << "Error: bad input => " << date << std::endl;
		else
		{
			trueValue = value * getExchangeRate(date);
			std::cout << date << " => " << value << " = " << trueValue << std::endl;
		}
	}
}

int	BitcoinExchange::parseValue(float value) const
{
	if (value < 0)
		return (std::cerr << "Error: not a positive number." << std::endl, 1);
	else if (value > 1000)
		return (std::cerr << "Error: too large a number." << std::endl, 2);
	return (0);
}


int	BitcoinExchange::parseDate(std::string date) const
{
	if (checkFormat(date))
		return (1);
	std::istringstream iss(date);
	int					year, month, day;
	int					maxDays = 31;
	char				delim;

	iss >> year >> delim >> month >> delim >> day;

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
		return (2);
	else if (year == 2009 && month == 1 && day < 02)
		return (3);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDays = 30;
	else if (month == 2)
	{
		if (isLeapYear(year))
			maxDays = 29;
		else
			maxDays = 28;
	}
	return (!(day <= maxDays));
}

bool BitcoinExchange::checkFormat(std::string date) const
{
	std::istringstream iss(date);
	std::string year, month, day;

	std::getline(iss, year, '-');
	std::getline(iss, month, '-');
	std::getline(iss, day, '-');

	if (year.empty() || month.empty() || day.empty()) // Check que le format est bien YYYY-MM-DD
		return (true);
	return (false);
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

float	BitcoinExchange::getExchangeRate(std::string key){
	float	test = 0.0;
	std::map<std::string, float>::iterator itb = this->_dataMap.begin();

	for (; itb != _dataMap.end(); itb++){
		if (itb->first == key){
			test = _dataMap[key];
			return test;
		}
	}
	if (itb == _dataMap.end()){
		itb = _dataMap.lower_bound(key);
		test = _dataMap[itb->first];
	}
	return test;
}
