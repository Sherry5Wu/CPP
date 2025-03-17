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
#include <cstdint>
#include "Data.hpp"
#include "Serializer.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

int main() {

	// set up the values
	Data src;
	src.index = 0;
	src.value = 5;

	uintptr_t	ptr;
	printInColor("The contents of src are:", PURPLE);
	std::cout << " * src->index=" << src.index << "\n";
	std::cout << " * src->value= " << src.value << "\n";

	ptr = Serializer::serialize(&src);
	printInColor("After serialize src, the ptr value is:", PURPLE);
	std::cout << " * ptr=" << ptr << "\n";

	Data* newSrc;
	newSrc = Serializer::deserialize(ptr);
	printInColor("After deserialize ptr, the newSrc value is:", PURPLE);
	std::cout << " * src->index=" << newSrc->index << "\n";
	std::cout << " * src->value= " << newSrc->value << "\n";

	return 0;
}
