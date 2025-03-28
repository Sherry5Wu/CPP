/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:00:39 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/28 13:02:57 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream> // for std::ifstream
#include <sstream> // for std::istringstream
#include <regex> // stand for regular expressions, for std::regex

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
		
		static std::tuple<std::string, std::string> lineSplit(std::string line, std::string del);
		static void	parsingDate(std::string& dateStr);
		static float	parsingValue(std::string& str_value, bool to_exchange);
		static bool	isLeapYear(int year);
		// void	outputRate();
};
