/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter3.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:43:55 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/13 14:43:55 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	(void)other;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other){
	(void)other;
	return *this;
}

/*--------------------------Type checking functions-------------------------*/

bool	ScalarConverter::charOverFlowed(int c){
	if (c < static_cast<int>(std::numeric_limits<char>::min())
		|| c > static_cast<int>(std::numeric_limits<char>::max())){
		return true; // overflowed
	}
	return false; // doesn't overflow
}

/**
 * Prototype:
 * 		int stoi(const std::string& str, std::size_t* pos = 0, int base = 10);
 *
 * This function converts a string to int, the first inconvertiable character's
 * postion saved in the pos. It can throw std::invalid_argument / std::out_of_range
 * exceptions.
 */
bool	ScalarConverter::isInt(const std::string& str, int& overflowFlag){
	try{
		std::size_t	pos;
		int	num = std::stoi(str, &pos);
		bool	isAnInteger;

		// pos euqals to str.length(), then it means all the characters are
		// converted.
		if (pos == str.length()){
			isAnInteger = true;
		}else{
			isAnInteger = false;
		}

		if (isAnInteger){
			if (charOverFlowed(num)){
				overflowFlag |= CharOverflow;
			}
			return true;
		}else{
			return false;
		}
	}catch (const std::invalid_argument& e){
		return false;
	}catch (const std::out_of_range& e){
		overflowFlag |= (IntOverflow | CharOverflow);
		return false;
	}catch (const std::exception& e){
		std::cout << "ScalarConvert::isInt() has an error: " << e.what() << std::endl;
		return false;
	}
}

bool	ScalarConverter::isFloat(const std::string& str, int& overflowFlag){

}

bool	ScalarConverter::isDouble(const std::string& str, int& overflowFlag){

}

bool	ScalarConverter::isPseudoFloat(const std::string& str){

}

bool	ScalarConverter::isPseudoDouble(const std::string& str){

}



/*-----------------------------checking overflow----------------------------*/

/**
 * Keypoints to understand:
 *  --FLT_MIN is the smallest positive non-zero value that can be represented by a
 * 		      float, not the smallest (most negative) value.
 *
 *  --(-FLT_MAX) is the largest negative finite value, i.e., the most negative number
 *            that can be represented by a float
 *  --FLT_MAX is the largest positive finite value that a float can hold.
 */
int	isOverflow(const double& num){
	if (num < nextafter(nextafter(-FLT_MAX, 0), -FLT_MAX)
		|| num > nextafter((FLT_MAX, 0), FLT_MAX)){
		return 3; // float overflow
	}
	if (num < nextafter(nextafter(INT_MIN,0), INT_MIN)
		|| num > nextafter(nextafter(INT_MAX,0), INT_MAX)){
		return 2; // int overflow
	}
	// when do we need this????
	if (num < nextafter(nextafter(CHAR_MIN, 0), CHAR_MIN)
		|| num > nextafter(nextafter(CHAR_MAX, 0), CHAR_MAX)){
		return 1; // char overflow
	}
	return 0; // it isn't overflow
}

/*--------------------------------print char-------------------------------*/

/**
 * @breif The rule to print:
 * 	-- If the char does overflow, than print "impossible";
 *  -- If the char is Not printable, then printf "Non displayble";
 *  -- else, print the char directly.
 */
void	printChar(const char& c, bool overflow){
	std::cout << "char: ";
	if (!overflow){
		if (std::isprint(static_cast<unsigned int>(c))){
			std::cout << "'" << c << "'\n";
		}else{
			std::cout << "Non displayable\n";
		}
	}else{
		std::cout << "impossible\n";
	}
}

/*--------------------------convertion functions-------------------------*/

void	charConvert(const std::string& str){
	std::cout << "char: " << "'" << str[0] << "'\n";
	std::cout << "int: " << static_cast<int>(str[0]) << "\n";
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f\n";
	std::cout << "double: " << static_cast<double>(str[0]) << ".0\n";
}

void	intConvert(const std::string& str){
	int	num = std::stoi(str);
	bool overflow = isOverflow(static_cast<double>(num));

	??????? Why we can convert the string to int , then check if it is overlow??

}

void	floatCovert(const std::string& str){

}

void	doubleConvert(const std::string& str){

}


void	ScalarConverter::convert(const std::string& str){

}
