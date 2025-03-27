/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:00:44 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/27 13:48:58 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& filename){
	std::ifstream file(filename);
	if (!file.is_open()){
		std::cerr << "Error: could not open database file.\n" << std::endl;
		exit(1);
	}

	// read the file content into rateDB_ map
	std::string line, date; // line for store each line's data
	float	rate;
	std::getline(file, line); // skip the header file
	while (std::getline(file, line)){
		
		// std::istringstream -> chang string into stream, so we can read
		// the string like reading from a file, to do extract, transform data
		std::istringstream ss(line);
		// get the content before ',' and saving into date
		// ss >> rate, read the content after ',' and saving into rate
		if (std::getline(ss, date, ',') && ss >> rate){
			rateDB_[date] = rate; // mapping date and rate
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& o):rateDB_(o.rateDB_){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o){
	if (this != &o){
		rateDB_ = o.rateDB_;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

float	BitcoinExchange::getExchangeRate(const std::string& date) const{
	// lower_bound(): to find a key that equal or greater than the given key
	auto	it = rateDB_.lower_bound(date);

	if (it == rateDB_.end() || it->first != date){
		if (it == rateDB_.begin()){
			return -1; // no earlier date available
		}
		it--;
	}
	// std::cout << "Used date: " << it->first << std::endl; // for debugging
	return it->second;
}

/**
 *  What if the input date is like yyyy-mm-d or yyyy-m-dd,???????
 */

void	BitcoinExchange::processInputFile(const std::string& inputFile) const{
	std::ifstream file(inputFile);
	if (!file.is_open()){
		std::cerr << "Error: could not open database file.\n" << std::endl;
		exit(1);
	}

	std::string line, date;
	float value;
	std::getline(file, line); // skip the header file

	while (std::getline(file, line)){
		std::istringstream ss(line);
		if (std::getline(ss, date, '|') && ss >> value){
			date.erase(date.find_last_not_of(" ") + 1); // trim space

			if (value < 0){
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000){
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			float rate = getExchangeRate(date);
			if (rate == -1){
				std::cerr << "Error: no histroical data for " << date << std::endl;
				continue;
			}
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	file.close();
}
