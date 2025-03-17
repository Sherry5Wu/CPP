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
#include "iter.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

// Sample function to apply on array elements
void printInt(int x) {
    std::cout << x << " ";
}

// Function template to demonstrate usage with various types
template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main() {
    // Test with int array
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    // Test with double array
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
    std::cout << "Double array: ";
    iter(doubleArr, 4, printElement<double>);
    std::cout << std::endl;

    // Test with char array
    char charArr[] = {'H', 'e', 'l', 'l', 'o'};
    std::cout << "Char array: ";
    iter(charArr, 5, printElement<char>);
    std::cout << std::endl;

    return 0;
}
