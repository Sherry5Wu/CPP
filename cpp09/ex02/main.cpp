/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:46:32 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/08 10:14:42 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include <chrono>


#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

// void	printInColor(const std::string&  msg, std::string color){
// 	std::cout << color << msg << RESET << std::endl;
// }

int main(int ac, char** av){
	if (ac < 2){
		std::cerr << "Usage: ./PmergeMe n1 n2 n3 [...]\n";
		exit(EXIT_FAILURE);
	}
	try{
		PmergeMe PM;
		
		// print the sorted array and get the sort time of vector
		auto startVec = std::chrono::high_resolution_clock::now();
		PM.importDataToVector(av + 1);
		std::cout << GREEN << "Before: " << RESET;
		PM.vectorPrint_();
		PM.vectorSort();
		auto endVec = std::chrono::high_resolution_clock::now();
		auto durationVec = std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec);
		std::cout <<GREEN << "After:  " << RESET;
		PM.vectorPrint_();
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::<vector> "
		<< durationVec.count() << " us\n";

		// get the sort time of deque
		auto startDeq = std::chrono::high_resolution_clock::now();
		PM.importDataToDeque(av + 1);
		PM.dequeSort();
		auto endDeq = std::chrono::high_resolution_clock::now();
		auto durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(endDeq - startDeq);
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::<deque> "
		<< durationDeq.count() << " us\n";

	}catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
    return 0;
}
