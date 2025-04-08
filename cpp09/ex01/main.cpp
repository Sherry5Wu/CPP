/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:46:32 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/07 10:32:39 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "RPN.hpp"


#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

// void	printInColor(const std::string&  msg, std::string color){
// 	std::cout << color << msg << RESET << std::endl;
// }

int main(int ac, char** av){

	if (ac != 2){
		std::cerr << "Usage: ./RPN \"<agrument>\"\n";
		return 1;
	}
	try{
		RPN	rpn;
		rpn.calculateResult(av[1]);
	}catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
    return 0;
}

// invalid input:
//   897*6-23+

//   89/0+2-(
//   80/2+
