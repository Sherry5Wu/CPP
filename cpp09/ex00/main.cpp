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


// #define RED "\033[0;31m"
// #define GREEN "\033[1;32m"
// #define PURPLE "\033[2;35m"
// #define RESET "\033[0;0m"

// void	printInColor(const std::string&  msg, std::string color){
// 	std::cout << color << msg << RESET << std::endl;
// }

int main(int ac, char** av){

	if (ac != 2){
		std::cerr << "Usage: ./btc <input_file>\n";
		return 1;
	}
	try{
		BitcoinExchange	btc;
		btc.importDB_("./data.csv");
		// (void)av;
		btc.exchange(av[1]);
	} catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
    return 0;
}


// int main (){
// 	std::string dateStr = "2009-12-01";

// 	std::regex format(R"((\d{4})-(\d{2})-(\d{2}))");
// 	std::smatch	result;

// 	// if (!std::regex_match(dateStr, result, format)){
// 	// 	throw(std::runtime_error("Error: format is wrong => " + dateStr)); // the date format is wrong
// 	// }
// 	std::regex_match(dateStr, result, format);
//     std::cout << "result[1].str()=" << result[1].str() << "\n";
// 	std::cout << "result[2].str()=" << result[2].str() << "\n";
// 	std::cout << "result[3].str()=" << result[3].str() << "\n";
// }



// bool   checkingLineFormat(const std::string& line, bool matchingForInput){
//     std::regex formatInput(R"(^\d{4}-\d{2}-\d{2} \| -?\d+(\.\d+)?$)");
//     std::regex formatDB(R"(^\d{4}-\d{2}-\d{2},-?\d+(\.\d+)?$)");
// 	std::smatch	result;
//     std::regex format;

//     if (matchingForInput == true){
//         format = formatInput;
//     } else {
//         format = formatDB;
//     }

//     if (!std::regex_match(line, result, format)){
// 		throw(std::runtime_error("Error: bad input => " + line)); // the date format is wrong
//         return false;
//     }
//     return true;
// }


// int main(){
// 	std::string line;
// 	std::ifstream file("./inputs/invalid.txt");
// 	std::getline(file, line);

// 	while (std::getline(file, line)){
// 		try{
// 			if (!checkingLineFormat(line, true)){
// 				std::cout <<  "FALSE\n";
// 			}
// 			else {
// 				std::cout <<  "TRUE\n";
// 			}
// 		} catch(const std::runtime_error& e){
// 			std::cout << e.what() << std::endl;
// 		}
// 	}
	// std::string line = "211-07-03 | 2";
	// try{
	// 	if (!checkingLineFormat(line, true)){
	// 		std::cout <<  "FALSE\n";
	// 	}
	// 	else {
	// 		std::cout <<  "TRUE\n";
	// 	}
	// } catch(const std::runtime_error& e){
	// 	std::cout << e.what() << std::endl;
	// }
// 	return 0;
// }
