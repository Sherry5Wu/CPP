/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:00:44 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/28 14:46:25 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

void	BitcoinExchange::importDB_(const std::string& fileName){
	std::string	line, date_str, rate_str;
	float	rate;

	std::ifstream	file(fileName);
	if (!file.is_open()){
		throw (std::runtime_error("Error: failed to open " + fileName));
	}
	if (file.peek() == std::ifstream::traits_type::eof()){
		throw (std::runtime_error(fileName + " is empty"));
	}
	std::getline(file, line); // skip the first line
	while(std::getline(file, line)){
		
		try{
			tie(date_str, rate_str) = BitcoinExchange::lineSplit(line, ",");
			parsingDate(date_str);
			rate = parsingValue(rate_str, false);
			rateDB_.insert(std::make_pair(date_str, rate));
		} catch (const std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
}

std::tuple<std::string, std::string> BitcoinExchange::lineSplit(std::string line, std::string del){
	std::string left, right;
	size_t	del_pos;

	if (line.empty()){
		throw(std::runtime_error("Error: empty line"));
	}
	del_pos = line.find(del);
	if (del_pos == std::string::npos){
		throw(std::runtime_error("Error: line format is wrong. \"" + line + "\""));
	}

	// split date and rate by delimeter
	left = line.substr(0, del_pos);
	del_pos += del.length();
	right = line.substr(del_pos, line.length() - del_pos);
	if (left.empty() || right.empty()){
		throw(std::runtime_error("Error: line format is wrong. \"" + line + "\""));
	}
	return std::make_tuple(left, right);
}

bool	BitcoinExchange::isLeapYear(int year){
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/**
 *  @brief the logic to parse the date
 *  1. checking if the date following the correct format;
 *  2. checking if any number overflow;
 *  3. checking if month and day in the correct range;
 *
 * Regex pattern:
 * 	1. \d{4}-\d{2}-\d{2};
 *  2. \d{4}-\d{1,2}-\d{1,2}:  \d{1,2}: Matches 1 or 2 digits for the month and day.
 *  3. \d{2}-[A-Za-z]{3}-\d{4}: A-Za-z]{3}: Matches exactly 3 alphabetic characters
 *                              for the month abbreviation (case insensitive)
 *  4. \d{2}-[A-Za-z]+-\d{4}: [A-Za-z]+: Matches one or more alphabetic characters
 *                            for the full month name (case insensitive).
 *
 * std::smatch : saving the matched result
 * 
 *
 */
void	BitcoinExchange::parsingDate(std::string& dateStr){
	// checking the format :YYYY-MM-DD
	// "\d{4}" : meaning 4 digits
	std::regex format(R"(\d{4}-\d{2}-\d{2})");
	std::smatch	result;

	if (!std::regex_match(dateStr, result, format)){
		throw(std::runtime_error("Error: format is wrong => " + dateStr)); // the date format is wrong
	}
	
	int	year, month, day;
	try{
		year = std::stoi(result[1].str());
		month = std::stoi(result[2].str());
		day = std::stoi(result[3].str());
	} catch (const std::overflow_error& e){
		std::cout << "Error: bad input => " << dateStr << std::endl;
	}
	
	int	daysIMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year)){
		daysIMonth[1] = 29;
	}
	// checking month is between 1~12, and day in the range
	if ((month < 1 || month > 12) || (day < 1 || day > daysIMonth[month - 1])){
		throw(std::runtime_error("Error: bad input => " + dateStr));
	}
}

/**
 * @brief Checking for the rate if it is in the corret range. This function will check
 *  for both input files: data.csv and input.txt.
 * 
 *  For data.csv, the rate should be a valid postive float number.
 *  For input.txt, the value should be between 0 ~ 1000.
 * 
 * @param str_value: the string type of value which needs to be parsed;
 *  isSmallRange: 
 *     true, degsin for checking input.txt, because the rate should be between 0 ~ 1000;
 *     false, for checking data.csv file, the rate should be a valid positive float number
 *  
 * 
 */
float	BitcoinExchange::parsingValue(std::string& str_value, bool isSmallRange){
	float num;
	size_t	pos;
	try{
		num = std::stof(str_value, &pos);
		if (pos != str_value.length()){
			throw (std::runtime_error("Error: value contains invalid characters => " + str_value));
		}
		if (num < 0){
			throw (std::runtime_error("Error: not a postive number"));
		}
		if (isSmallRange && num > 1000){
			throw (std::runtime_error("Error: too large a number"));
		}
		return num;
	} catch (const std::overflow_error& e){
		std::cerr << "Error: value overflow => " << str_value << std::endl;
	}
}

void	BitcoinExchange::outputRate();

void	BitcoinExchange::getPrice(const char* inputFileName){

}
