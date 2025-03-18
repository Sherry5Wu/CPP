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
#include "easyfind.hpp"
#include <vector>
#include <list>


#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

int main() {
    std::vector<int> vec = {-1, 0, 1 , 2 , 3};
    std::list<int>  lst = {100, 200, 3, 400, 500};

    std::vector<int>::iterator  pVec = vec.begin();
    std::list<int>::iterator    pLst = lst.begin();

    std::cout << "The elements in Vecter are: ";
    for (; pVec != vec.end(); pVec++){
        std::cout << *pVec << ", ";
    }
    std::cout << std::endl;

    std::cout << "The elements in List are: ";
    for (; pLst != lst.end(); pLst++){
        std::cout << *pLst << ", ";
    }
    std::cout << std::endl;


    printInColor("\n1. trying to find '3' in the vector", PURPLE);
    // easyfind() return the iterator, *easyfind() will get the value
    std::cout << "Found: " << *easyfind(vec, 3) << " is in the Vector\n";

    printInColor("\n2. trying to find '20' in the vector", PURPLE);
    try{
        std::cout << *easyfind(vec, 20) << "is the Vector\n";
    } catch (const std::runtime_error& e){
        std::cout << e.what() << std::endl;
    }

    printInColor("\n3. trying to find '100' in the List", PURPLE);
    std::cout << "Found: " << *easyfind(lst, 100) << " is in the Vector\n";

    printInColor("\n4. trying to find '5' in the List", PURPLE);
    try{
        std::cout << *easyfind(lst, 5) << "is the Vector\n";
    } catch (const std::runtime_error& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}
