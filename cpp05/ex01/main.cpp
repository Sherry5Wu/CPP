/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:18 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 14:03:18 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0;0m"

static void	constructorAndAssignment(){
	std::cout << PURPLE << "\n1. parameterized constructor -- positive case\n" << RESET;

	try{
		Bureaucrat david("David", 42);
		david.print();
	}catch (const std::exception& e){
		std::cerr << RED << "Exception: " << e.what() << std::endl;
	}

Need more test cases??????

	std::cout << PURPLE << "\n2. parameterized constructor -- negative case\n" << RESET;
	Bureaucrat tooHigh("Too_high", 0);
}

int main(){
	std::cout << GREEN << "------------Testing consructors and assignment operator"
	<<"----------------\n" << RESET;
	constructorAndAssignment();

	return 0;
}

