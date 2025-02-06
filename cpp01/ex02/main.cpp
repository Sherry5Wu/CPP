/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:23:21 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 11:23:21 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void){
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	// print the the memory address
	std::cout << "Bellow are addresses:" << std::endl;
	std::cout << "  * string:" << &string << std::endl;
	std::cout << "  * stringPTR:" << stringPTR << std::endl;
	std::cout << "  * stringREF:" << &stringREF << std::endl;

	// print the values
	std::cout << "Bellow are values:" << std::endl;
	std::cout << "  * string:" << string << std::endl;
	std::cout << "  * stringPTR:" << *stringPTR << std::endl;
	std::cout << "  * stringREF:" << stringREF << std::endl;

	return (0);
}
