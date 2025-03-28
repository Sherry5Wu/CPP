/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:46:32 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/17 08:46:32 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"


#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

// void	printInColor(const std::string&  msg, std::string color){
// 	std::cout << color << msg << RESET << std::endl;
// }

int main(int ac, char** av){

	if (ac != 2){
		std::cerr << "Usage: .btc <input_file>\n";
		return 1;
	}
	try{
		BitcoinExchange	btc;
		btc.importDB_("data.csv");
		btc.exchange(av[1]);
	} catch(){
		??????????
	}
    return 0;
}
