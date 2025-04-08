/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:00:39 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/08 13:45:11 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream> // for std::ifstream
#include <sstream> // for std::istringstream
#include <regex> // stand for regular expressions, for std::regex
// #include <cmath> // for pow()

class BitcoinExchange{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void	importDB_(const std::string& fileName);
		void	exchange(const char* inputFileName);

	private:
		std::map<std::string, float>	rateDB_;

		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);

		std::tuple<std::string, std::string> lineSplit(std::string line, std::string del);
		bool	checkingLineFormat(const std::string& line, bool matchingForInput);
		bool	parsingDate(std::string& dateStr);
		float	parsingValue(std::string& str_value, bool to_exchange);
		bool	isLeapYear(int year);
};
