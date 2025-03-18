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

static void arrayTypeTesting(){
        printInColor("\n1. Test with int array", PURPLE);
        int intArr[] = {1, 2, 3, 4, 5};
        std::cout << "Int array: ";
        iter(intArr, 5, printInt);

        printInColor("\n2. Test with double array", PURPLE);
        double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
        std::cout << "Double array: ";
        iter(doubleArr, 4, printElement<double>);

        printInColor("\n3. Test with char array", PURPLE);
        char charArr[] = {'H', 'e', 'l', 'l', 'o'};
        std::cout << "Char array: ";
        iter(charArr, 5, printElement<char>);
        std::cout << std::endl;
}

class Print{
    public:
        void    operator()(int x) const {std::cout << x << " ";}
};

static void functionTypeTesting(){
    printInColor("\n1. Test with lambda function", PURPLE);
    int arr[5] = {10, 11, 12 ,13 ,14};
    std::cout << "array: ";
    iter(arr, 5, [](int x){std::cout << x << " ";}); // lambda : [](parameter list) {function body}
    std::cout << std::endl;

    printInColor("\n2. Test with functor", PURPLE);
    int arr1[5] = {10, 11, 12 ,13 ,14};
    Print print;
    iter(arr1, 5, print);
    std::cout << std::endl;

}

int main() {
    printInColor("<------------Different array type Testing-------------->", GREEN);
    arrayTypeTesting();

    printInColor("\n<------------Different function type Testing-------------->", GREEN);
    functionTypeTesting();

    return 0;
}
