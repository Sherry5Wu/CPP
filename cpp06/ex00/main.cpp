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
#include <string>
#include "ScalarConverter.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"


// int main(int ac, char** av){
// 	if (ac == 2){
// 		ScalarConverter::convert(av[1]);
// 	}else{
// 		std::cout << "Wrong parameter number\n";
// 	}

// 	return 0;
// }


void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

#if 1
static void	charTypeTesting(){
	printInColor("1. input: a", PURPLE);
	ScalarConverter::convert("a");
	std::cout << std::endl;

	printInColor("2. input: *", PURPLE);
	ScalarConverter::convert("*");
	std::cout << std::endl;

	printInColor("3. input: &", PURPLE);
	ScalarConverter::convert("&");
	std::cout << std::endl;

	printInColor("4. input: b", PURPLE);
	ScalarConverter::convert("b");
	std::cout << std::endl;

	printInColor("5. invalid input: +a", PURPLE);
	ScalarConverter::convert("+a");
	std::cout << std::endl;

	printInColor("6. input: M", PURPLE);
	ScalarConverter::convert("M");
	std::cout << std::endl;
}

static void	intTypeTesting(){
	printInColor("1. input: 0", PURPLE);
	ScalarConverter::convert("0");
	std::cout << std::endl;

	printInColor("2. input: 2", PURPLE);
	ScalarConverter::convert("2");
	std::cout << std::endl;

	printInColor("3. input: -123", PURPLE);
	ScalarConverter::convert("-123");
	std::cout << std::endl;

	printInColor("4. input: -129", PURPLE);
	ScalarConverter::convert("-129");
	std::cout << std::endl;

	printInColor("5. input: -2147483648", PURPLE);
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;

	printInColor("6. input: +2147483647", PURPLE);
	ScalarConverter::convert("+2147483647");
	std::cout << std::endl;

	printInColor("7. input: +2147483648", PURPLE);
	ScalarConverter::convert("+2147483648");
	std::cout << std::endl;

	printInColor("8. input: 2154785335545457845435321215545452124536655444111225544411", PURPLE);
	ScalarConverter::convert("2154785335545457845435321215545452124536655444111225544411");
	std::cout << std::endl;

	printInColor("9. invalid input: ++10", PURPLE);
	ScalarConverter::convert("++10");
	std::cout << std::endl;

	printInColor("10. invalid input: -+10", PURPLE);
	ScalarConverter::convert("-+10");
	std::cout << std::endl;


	printInColor("11. invalid input: 123a", PURPLE);
	ScalarConverter::convert("123a");
	std::cout << std::endl;

	printInColor("12. invalid input: -25a4", PURPLE);
	ScalarConverter::convert("25a4");
	std::cout << std::endl;
}

static void	floatTypeTesting(){
	printInColor("1. invalid input: 4.0.0f -- with two dots", PURPLE);
	ScalarConverter::convert("4.0.0f");
	std::cout << std::endl;

	printInColor("2. invalid input: .42f -- start with dot", PURPLE);
	ScalarConverter::convert(".42f");
	std::cout << std::endl;

	printInColor("3. invalid input: 42f. -- end with dot", PURPLE);
	ScalarConverter::convert("42f.");
	std::cout << std::endl;

	printInColor("4. invald input: 42.3ff -- double f", PURPLE);
	ScalarConverter::convert("42.3ff");
	std::cout << std::endl;

	printInColor("5. invald input: 42.3af -- invalid character", PURPLE);
	ScalarConverter::convert("42.3af");
	std::cout << std::endl;

	printInColor("6. input: 0.0f", PURPLE);
	ScalarConverter::convert("0.0f");
	std::cout << std::endl;

	printInColor("7. input: -4.2f", PURPLE);
	ScalarConverter::convert("-4.2f");
	std::cout << std::endl;

	printInColor("8. input: +3.2f", PURPLE);
	ScalarConverter::convert("+3.2f");
	std::cout << std::endl;

	printInColor("9. float overflow input: 2554121564813212312121524841231215248645.0f", PURPLE);
	ScalarConverter::convert("2554121564813212312121524841231215248645.0f");
	std::cout << std::endl;

	printInColor("10. double overflow input: 2554121564813212312121524841231215248645123121121211.0f", PURPLE);
	ScalarConverter::convert("2554121564813212312121524841231215248645123121121211.0f");
	std::cout << std::endl;

	printInColor("11. input: nanf", PURPLE);
	ScalarConverter::convert("nanf");
	std::cout << std::endl;

	printInColor("12. input: -inff", PURPLE);
	ScalarConverter::convert("-inff");
	std::cout << std::endl;

	printInColor("13. input: +inff", PURPLE);
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
}

static void	doubleTypeTesting(){
	printInColor("1. invalid input: 4.0.0 -- with two dots", PURPLE);
	ScalarConverter::convert("4.0.0");
	std::cout << std::endl;

	printInColor("2. invalid input: .42 -- start with dot", PURPLE);
	ScalarConverter::convert(".42");
	std::cout << std::endl;

	printInColor("3. invalid input: 42. -- end with dot", PURPLE);
	ScalarConverter::convert("42.");
	std::cout << std::endl;

	printInColor("4. invald input: 42.3a -- invalid character", PURPLE);
	ScalarConverter::convert("42.3a");
	std::cout << std::endl;

	printInColor("5. input: 0.0", PURPLE);
	ScalarConverter::convert("0.0");
	std::cout << std::endl;

	printInColor("6. input: -4.2", PURPLE);
	ScalarConverter::convert("-4.2");
	std::cout << std::endl;

	printInColor("7. input: +3.2", PURPLE);
	ScalarConverter::convert("+3.2");
	std::cout << std::endl;

	printInColor("9. input: nan", PURPLE);
	ScalarConverter::convert("nan");
	std::cout << std::endl;

	printInColor("10. input: -inf", PURPLE);
	ScalarConverter::convert("-inf");
	std::cout << std::endl;

	printInColor("11. input: +inf", PURPLE);
	ScalarConverter::convert("+inf");
	std::cout << std::endl;

	printInColor("12. invalid input: inf", PURPLE);
	ScalarConverter::convert("inf");
	std::cout << std::endl;

	printInColor("13. double overflow input: 2554121564813212312121524841231215248645123121121211.0", PURPLE);
	ScalarConverter::convert("2554121564813212312121524841231215248645123121121211.0");
	std::cout << std::endl;
}

int	main(){
	printInColor("<---------Testing for char type---------->", GREEN);
	charTypeTesting();

	printInColor("<---------Testing for Int type---------->", GREEN);
	intTypeTesting();

	printInColor("<---------Testing for Float type---------->", GREEN);
	floatTypeTesting();

	printInColor("<---------Testing for double type---------->", GREEN);
	doubleTypeTesting();
	return 0;
}
#endif



