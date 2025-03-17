/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:39:04 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/13 13:39:04 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*--------------------------class basic functions-------------------------*/

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
/**
 * @brief how to check if the passed str is a char?
 *  1. the lenght of the str is 1;
 *  2. the character is not a digit;
 *  3. the character is printable.
 *
 * Why convert str to unsigned char type?
 *  isdigit is expecting a unsigned char type value. If we don't convert it,
 *  it might cause some undefined error.
 *
 * @return true: the input is a char type (but not sure if it is printable)
 * false: the input it is not a char type;
 */
bool	isChar(const std::string& str){
	return (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))
			&& std::isprint(str[0]));
}

/**
 * @return true: the input is a int type and won't overflow;
 *  false: the input is not a int type or it overflow.
 */
bool	isInt(const std::string& str){
	size_t	i = 0;
	size_t	length = str.length();

	if ((str[i] == '-' || str[i] == '+') && length > 1){
		i++;
	}
	for (; i < length ; i++){
		if (!std::isdigit(static_cast<unsigned char>(str[i]))){
			return false;
		}
	}
	return true;
}

bool	isFloat(const std::string& str){
	size_t	length = str.length();

	// if the length of the str less than 4, it must be invalid.
	if (length < 4){
		return false;
	}

	//  there is no 'f' or 'f' is not at the end of the string, return false
	size_t	f_pos = str.find('f');
	if (f_pos == std::string::npos || f_pos != length - 1){
		return false;
	}
	// checking for the '.' postion
	size_t	dot = str.find('.');
	if (dot == std::string::npos || dot == 0 || str.find('.', (dot + 1)) != std::string::npos){
		return false;
	}

	// checking if just contains digit and '.' except the last character.
	size_t i = 0;
	if ((str[i] == '-' || str[i] == '+') && length >= 5)
		i++;
	for (; i < length - 1; i++){
		if (!(std::isdigit(static_cast<unsigned char>(str[i]))
			|| str[i] == '.')){
			return false;
		}
	}
	return true;
}

/**
 * @brief hecking if the format follows the doublt rules(contain only digit and '.',
 * and only contain one dot. It is not starting or ending with the dot)
 */
bool	isDouble(const std::string& str){
	size_t	length = str.length();
	// if the length of the str less than 3, it must be invalid.
	if (length < 3){
		return false;
	}
	size_t	i = 0;
	size_t	dot = str.find('.');

	// Here to make sure it only contains one dot and the dot isn't at the
	// front or end
	if (dot == 0 || dot == length || dot == std::string::npos
		|| str.find('.', (dot + 1)) != std::string::npos){
		return false;
	}
	if ((str[i] == '-' || str[i] == '+') && length >= 4){
		i++;
	}
	for (; i < str.length(); i++){
		if (!(std::isdigit(static_cast<unsigned char>(str[i])) || str[i] == '.')){
			return false;
		}
	}
	return true;
}

bool	isPseudoFloat(const std::string& str){
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	return false;
}

bool	isPseudoDouble(const std::string& str){
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	return false;
}

/*--------------------------------Check Type-------------------------------*/

/**
 * @brief the function will check which type the passed string belong to,
 * and get the overflow information.
 */
Type	checkType(const std::string& str){
	if (isChar(str)){
		return Type::Char;
	}else if(isInt(str)){
		return Type::Int;
	}else if(isPseudoFloat(str)){
		return Type::PseudoFloat;
	}else if(isFloat(str)){
		return Type::Float;
	}else if (isPseudoDouble(str)){
		return Type::PseudoDouble;
	}else if (isDouble(str)){
		return Type::Double;
	}else {
		return Type::Unknow;
	}
}

/**
 * don't need consider unknow type, it will check beforehand
 */
int	getOverflowInfo(const std::string& str, const Type& type){
	int		overflowFlag = 0;
	double	num = 0;

	try{
		size_t	pos;
		num = std::stod(str, &pos);
		if (type == Type::Float){
			if (pos != str.length() - 1){
				return -1;
			}
		} else if (pos != str.length()){
			return -1;
		}
	} catch (const std::out_of_range& e){
		overflowFlag |= DoubleOverflow;
		return overflowFlag; //double level overflow
	} catch (const std::invalid_argument& e){
		return -1;
	} catch (const std::exception& e){
		std::cout << "ScalarConverter::isDouble() error: " << e.what() << std::endl;
		return -1;
	}
	if (num < nextafter(nextafter(-FLT_MAX, 0), -FLT_MAX)
		|| num > nextafter(nextafter(FLT_MAX, 0), FLT_MAX)){
		overflowFlag |= FloatOverflow;
		return overflowFlag; // float level overflow
	}
	if (num < nextafter(nextafter(INT_MIN,0), INT_MIN)
		|| num > nextafter(nextafter(INT_MAX,0), INT_MAX)){
		overflowFlag |= IntOverflow;
		return overflowFlag; // int level overflow
	}
	if (num < nextafter(nextafter(CHAR_MIN, 0), CHAR_MIN)
		|| num > nextafter(nextafter(CHAR_MAX, 0), CHAR_MAX)){
		overflowFlag |= CharOverflow;
		return overflowFlag; // char level overflow
	}
	return overflowFlag; // it isn't overflow at any type
}

/*--------------------------convertion functions-------------------------*/

void	numConverter(double num, int overflowFlag){
	switch (overflowFlag){
		case 4: // float level overflow
			std::cout << "char: " << "impossbile\n";
			std::cout << "int: " << "impossbile\n";
			std::cout << "float: " << "impossbile\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "double: " << num << "\n";
			break;
		case 2: // int level overflow
			std::cout << "char: " << "impossbile\n";
			std::cout << "int: " << "impossbile\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(num) << "f\n";
			std::cout << "double: " << num << "\n";
			break;
		case 1: // char level overflow
			std::cout << "char: " << "impossbile\n";
			std::cout << "int: " << static_cast<int>(num) << "\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(num) << "f\n";
			std::cout << "double: " << num << "\n";
			break;
		default: // no overflow
			if (std::isprint(static_cast<unsigned char>(num))){
				std::cout << "char: " << static_cast<char>(num) << "\n";
			} else {
				std::cout << "char: Not Displayable" << "\n";
			}
			std::cout << "int: " << static_cast<int>(num) << "\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(num) << "f\n";
			std::cout << "double: " << num << "\n";
	}
}

void	converter(Type type, const std::string& str,int overflowFlag){
	double	num = std::stod(str);
	switch (type){
		case Type::PseudoFloat:
			std::cout << "char: " << "impossbile\n";
			std::cout << "int: " << "impossbile\n";
			std::cout << "float: " << str << "\n";
			std::cout << "double: " << str.substr(0, str.length() - 1) << "\n";
			break ;
		case Type::PseudoDouble:
			std::cout << "char: " << "impossbile\n";
			std::cout << "int: " << "impossbile\n";
			std::cout << "float: " << str << "f\n";
			std::cout << "double: " << str << "\n";
			break ;
		default:
			numConverter(num, overflowFlag);
	}
}

void	ScalarConverter::convert(const std::string& str){
	if (str.empty()){
		std::cout << "Hey, friend! You didn't input anything\n";
		return ;
	}
	int	overflowFlag = 0;
	Type	type = checkType(str);

	if (type == Type::Unknow){
		std::cout << "char: " << "impossbile\n";
		std::cout << "int: " << "impossbile\n";
		std::cout << "float: " << "impossbile\n";
		std::cout << "double: " << "impossbile\n";
		return ;
	} else if (type == Type::Char){
		std::cout << "char: '" << str[0] << "'\n";
		std::cout << "int: " << static_cast<int>(str[0]) << "\n";
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f\n";
		std::cout << "double: " << static_cast<double>(str[0]) << ".0\n";
		return ;
	}
	overflowFlag = getOverflowInfo(str, type);
	// if it is double level overflow, than it should be all impossbile
	if (overflowFlag == 8){
		std::cout << "char: " << "impossbile\n";
		std::cout << "int: " << "impossbile\n";
		std::cout << "float: " << "impossbile\n";
		std::cout << "double: " << "impossbile\n";
		return ;
	}
	converter(type, str, overflowFlag);
}

/*---------------------------For Debugging----------------------------------*/
// void	printType(Type& type){
// 	std::cout << "Type=";
// 	switch (type){
// 		case Type::Char:
// 			std::cout << "char\n";
// 			break ;
// 		case Type::Int:
// 			std::cout << "int\n";
// 			break ;
// 		case Type::Float:
// 			std::cout << "float\n";
// 			break ;
// 		case Type::Double:
// 			std::cout << "double\n";
// 			break ;
// 		case Type::PseudoFloat:
// 			std::cout << "pseudofloat\n";
// 			break ;
// 		case Type::PseudoDouble:
// 			std::cout << "pseudodouble\n";
// 			break ;
// 		default:
// 			std::cout << "invalid type\n";
// 	}
// }
