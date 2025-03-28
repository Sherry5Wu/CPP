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
#include "MutantStack.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

#if 1
static void fromSubject(){
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
}

static void loopStack(MutantStack<int> mstack){
    std::cout << "Numbers in the stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static void selfTesting(){
    MutantStack<int> mstack;

    printInColor("\n1. Testing push function. Push 10, 20 ,30 ,40 into stack", PURPLE);
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    loopStack(mstack);

    printInColor("\n2. Testing top function", PURPLE);
    std::cout << "Number at the top stack: " << mstack.top() << std::endl;

    printInColor("\n3. Testing pop function", PURPLE);
    mstack.pop();
    std::cout << "After popping one number of from stack, the top number is: " << mstack.top() << std::endl;

    printInColor("\n4. Loop all the numbers using iterator", PURPLE);
    loopStack(mstack);

    printInColor("\n5. Reverse way to loop all the numbers using iterator", PURPLE);
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}

int main(){
    printInColor("<---------------------From Subject------------------------->", GREEN);
    fromSubject();

    printInColor("<---------------------Self Testing------------------------->", GREEN);
    selfTesting();
    return 0;
}
#endif

/*-------------------------------List Container---------------------------------*/
#if 0
#include <list>

int main(){
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	return 0;
}
#endif


/*-------------------------------Vector Container---------------------------------*/
#if 0

#include <vector>
int main(){
	std::vector<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::vector<int>::iterator it = mstack.begin();
	std::vector<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	return 0;
}
#endif
