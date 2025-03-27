/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:00:39 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/27 13:40:07 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream> // for std::ifstream
#include <sstream> // for std::istringstream


class BitcoinExchange{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& o);
		BitcoinExchange& operator=(const BitcoinExchange& o);
		~BitcoinExchange();

		float	getExchangeRate(const std::string& date) const;
		void	processInputFile(const std::string& inputFile) const;

	private:
		std::map<std::string, float>	rateDB_;
};
