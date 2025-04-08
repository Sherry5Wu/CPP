/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:00:44 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/07 10:01:04 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

/**
 * @brief checking the format each line of data file and input file.
 * Data file format: YYYY-MM-DD,<float number>
 * Input file format: YYYY-MM-DD | <float number>
 *
 * Regex pattern:
 * 	1. \d{4}-\d{2}-\d{2};
 *  2. \d{4}-\d{1,2}-\d{1,2}:  \d{1,2}: Matches 1 or 2 digits for the month and day.
 *  3. \d{2}-[A-Za-z]{3}-\d{4}: A-Za-z]{3}: Matches exactly 3 alphabetic characters
 *                              for the month abbreviation (case insensitive)
 *  4. \d{2}-[A-Za-z]+-\d{4}: [A-Za-z]+: Matches one or more alphabetic characters
 *                            for the full month name (case insensitive).
 */
bool    BitcoinExchange::checkingLineFormat(const std::string& line, bool matchingForInput){
    std::regex formatInput(R"(^\d{4}-\d{2}-\d{2} \| -?\d+(\.\d+)?$)");
    std::regex formatDB(R"(^\d{4}-\d{2}-\d{2},-?\d+(\.\d+)?$)");
	std::smatch	result;
    std::regex format;

    if (matchingForInput == true){
        format = formatInput;
    } else {
        format = formatDB;
    }

    if (!std::regex_match(line, result, format)){
		throw(std::runtime_error("Error: bad input => " + line)); // the date format is wrong
        return false;
    }
    return true;
}

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
			if (checkingLineFormat(line, false)){
                tie(date_str, rate_str) = BitcoinExchange::lineSplit(line, ",");
				if (!parsingDate(date_str)){
					throw(std::runtime_error("Error: bad input => " + line));
				}
                rate = parsingValue(rate_str, false);
                rateDB_.insert(std::make_pair(date_str, rate));
            }
		}catch (const std::exception& e){
			std::cerr << e.what() << std::endl;
        }
	}
}

/**
 * @brief In this function, we will split the line by the passed delimiters. After we
 * got the left (date part) and right (value part), we will valid the format for each
 * part.
 */
std::tuple<std::string, std::string> BitcoinExchange::lineSplit(std::string line, std::string del){
	std::string left, right;
	size_t	del_pos;

	// split date and rate by delimeter
	del_pos = line.find(del);
	left = line.substr(0, del_pos);
	del_pos += del.length();
	right = line.substr(del_pos, line.length() - del_pos);
	return std::make_tuple(left, right);
}

bool	BitcoinExchange::isLeapYear(int year){
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/**
 *  @brief The function is for validing if the passed date is a correct real date.
 * 	The logic to parse the date
 *  1. checking if the date following the correct format;
 *  2. checking if any number overflow;
 *  3. checking if month and day in the correct range;
 *
 * std::smatch : saving the matched result *
 */
bool	BitcoinExchange::parsingDate(std::string& dateStr){
	// checking the format :YYYY-MM-DD
	// "\d{4}" : meaning 4 digits
    // but remember to add "()" to each catch group, like "(\d{4})", then it
    // catch the year, month and day.
	std::regex format(R"((\d{4})-(\d{2})-(\d{2}))");
	std::smatch	result;

    std::regex_match(dateStr, result, format);
	int	year, month, day;
	try{
		year = std::stoi(result[1].str());
		month = std::stoi(result[2].str());
		day = std::stoi(result[3].str());
	} catch (const std::exception& e){
        std::cout << e.what() << std::endl;
		return false;
    }

	int	daysIMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year)){
		daysIMonth[1] = 29;
	}
	// checking month is between 1~12, and day in the range
	if ((month < 1 || month > 12) || (day < 1 || day > daysIMonth[month - 1])){
		return false;
	}
	return true;
}


/**
 * @brief Checking for the rate if it is in the corret range. This function will check
 *  for both input files: data.csv and input.txt.
 *
 *  For data.csv, the rate should be a valid positive float number.
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
			throw (std::runtime_error("Error: not a positive number."));
		}
		if (isSmallRange && num > 1000){
			throw (std::runtime_error("Error: too large a number."));
		}
		return num;
	} catch (const std::overflow_error& e){
		std::cerr << "Error: value overflow => " << str_value << std::endl;
        throw;  // ensure we don't fall off the end. and if we don't add this, when
                // comppile it, it will have error "non-void function does
                // not return a value in all control paths"
	}
}

/**
 *
 *
 * The difference between open() and is_open():
 * 	Key Differences:
		Feature	       inFile.open("file.txt")	         inFile.is_open()
		Purpose	       Opens a file	                     Checks if a file is open
		Return         Type	void (no return value)	     bool (true if open, false otherwise)
		Usage	       Used to explicitly open a file	 Used to verify if a file is open
		When to use	   When opening a file after 	     After opening to check if it was successful
 * 				       declaring ifstream
 */
void	BitcoinExchange::exchange(const char* inputFileName){
	std::string	line, date, closest_date, str_quanlity;
	float	quanlity;

	std::ifstream	inFile(inputFileName);
	if (!inFile.is_open()){
		throw (std::runtime_error("Error: can't open input file"));
	}
	if (inFile.peek() == std::ifstream::traits_type::eof()){
		throw (std::runtime_error("Input file is empty"));
	}

	std::getline(inFile, line); // skip the first line(title line)
	while (std::getline(inFile, line)){
            try{
				if (checkingLineFormat(line, true)){
                tie(date, str_quanlity) = lineSplit(line, " | ");
				if (!parsingDate(date)){
					throw (std::runtime_error("Error: bad input => " + line));
				}
                quanlity = parsingValue(str_quanlity, true);

                // there are three conditions here:
                //    1. the date exists in the rateDB_;
                //    2. the date is greater than the last element, so find the closest_date;
                //    3. the date is smaller than the first element, so there is no closet_date;
                if (rateDB_.find(date) == rateDB_.end()){
                    // If date matches a key: itr points to it.
                    // If date is between keys: itr points to the next greater key.
                    // If date is smaller than all keys: itr == _DB.begin().
                    std::map<std::string, float>::iterator	itr = rateDB_.lower_bound(date);
                    if (itr == rateDB_.begin()){
                        throw (std::runtime_error("Error: \"" + date + "\", too early to find a matching exchange rate"));
                    } else {
                        // std::prev : std::prev(itr) returns an iterator one step before itr,
                        // like --itr but without modifying itr itself.
                        closest_date = std::prev(itr)->first;
                    }
                } else {
                    closest_date = date;
                }
                std::cout << date << " => " << quanlity << " = " << quanlity * rateDB_[closest_date] << std::endl;
            	}
            }catch (std::exception& e){
                std::cerr << e.what() << std::endl;
    	}
	}
}
