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
#include "Array.hpp"
#include <stdexcept>

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

int main() {
    try{
        printInColor("\n1. testing default constructor", PURPLE);
        Array<int> intArr1;
        std::cout << "Size of intArr1: " << intArr1.size() << std::endl;

        printInColor("\n2. testing parameterized constructor", PURPLE);
        Array<float> floatArr(5);
        std::cout << "Size of floatArr: " << floatArr.size() << std::endl;

        printInColor("\n3. testing copy constructor and assignment operator", PURPLE);
        for (unsigned int i = 0; i < floatArr.size(); i++){
            floatArr[i] = i + 2.1;
        }

        std::cout << "Original floatArr is: ";
        for (unsigned int i = 0; i < floatArr.size(); i++){
            std::cout << floatArr[i] << ", ";
        }
        std::cout << std::endl;

        std::cout << "\nAfter copying floatArr to arr1, the arr1 is: ";
        Array<float> arr1(floatArr);
        for (unsigned int i = 0; i < arr1.size(); i++){
            std::cout << arr1[i] << ", ";
        }
        std::cout << std::endl;

        std::cout << "\nAfter arr2 = floatArr, the arr2 is: ";
        Array<float> arr2;
        arr2 = floatArr;
        for (unsigned int i = 0; i < arr2.size(); i++){
            std::cout << arr2[i] << ", ";
        }
        std::cout << std::endl;

        printInColor("\n4. testing deep copy", PURPLE);
        std::cout << "Change the value of floatArr[0] to 100.5, it won't influence arr1 and arr2\n";
        floatArr[0] = 100.5;
        std::cout << "floatArr[0] = " << floatArr[0] << std::endl;
        std::cout << "arr1[0] = " << arr1[0] << std::endl;
        std::cout << "arr2[0] = " << arr2[0] << std::endl;

        printInColor("\n5. testing const array, set the size to 4", PURPLE);
        const Array<float> doubleArr(4);
        std::cout << "Size of doubleArr: " << doubleArr.size() << std::endl;

        printInColor("\n6. testing index is out of range", PURPLE);
        floatArr[5] = 0;

    } catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
