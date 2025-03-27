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
#include "Span.hpp"
#include <vector>
#include <list>


#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

#if 1
static void testFromSubject(){
    Span sp = Span(-5);
    printInColor("\n1.Add number '6, 3, 17, 9, 11' into sp", PURPLE);
    sp.addNumber(7);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.printNumbers();
    std::cout << std::endl;
    std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
    sp.printShortestSpanNumbers();
    std::cout << "Longest span is: " << sp.longestSpan() << std::endl;
    sp.printLongestSpanNumbers();
}


static void selfTesing(){
    printInColor("\n2. Testing for big range, 10000 numbers", PURPLE);
    std::vector<int>    bigNums(10000);
    for (size_t i =0; i < bigNums.size(); i++){
        bigNums[i] = i;
    }
    Span bigSp = Span(-10000);
    bigSp.addNumber(bigNums.begin(), bigNums.end());
    std::cout << "Shortest span is: " << bigSp.shortestSpan() << std::endl;
    std::cout << "Longest span is: " << bigSp.longestSpan() << std::endl;
    bigSp.printLongestSpanNumbers();
}
#endif

static void negativeTesting(){
    printInColor("\n3. No numbers in Span, try to get the shortest span", PURPLE);
    Span    sp(3);
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::logic_error& e){
        std::cout << e.what() << std::endl;
    }

    printInColor("\n4. No numbers in Span, try to get the longest span", PURPLE);
    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::logic_error& e){
        std::cout << e.what() << std::endl;
    }

    printInColor("\n5. Trying to add extra number when the Span is full", PURPLE);
    try {
        sp.addNumber(100);
        sp.addNumber(25);
        sp.addNumber(-2);
        sp.addNumber(0);
    } catch (const std::overflow_error& e){
        std::cout << e.what() << std::endl;
    }

    printInColor("\n6. Trying to add bigger range than Span's limit", PURPLE);
    std::vector<int>    bigNums(200);
    for (size_t i =0; i < bigNums.size(); i++){
        bigNums[i] = i;
    }
    try {
        Span sp(199);
        sp.addNumber(bigNums.begin(), bigNums.end());
    } catch (const std::overflow_error& e){
        std::cout << e.what() << std::endl;
    }
}

int main() {
    printInColor("<------------------------From Subject---------------------------->", GREEN);
    testFromSubject();

    std::cout << std::endl;
    printInColor("<-------------------------Self Testing----------------------------->", GREEN);
    selfTesing();

    std::cout << std::endl;
    printInColor("<-------------------------Negative Testing----------------------------->", GREEN);
    negativeTesting();

    return 0;
}
