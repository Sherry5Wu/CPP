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
bool	ScalarConverter::isChar(const std::string& str){
	return (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))
			&& std::isprint(str[0]));
}

bool	isInt(const std::string& str){
	size_t	i = 0;
	size_t	length = str.length();

	// here checking length is very important
	if ((str[i] == '-' || str[i] == '+') && length > 1)
		i++;
	for (; i < length; i++){
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

/**
 * @return true: the num overflow for char type;
 * false: the num doesn't overflow for char type.
 */
bool	ScalarConverter::isOverflowCharType(int num){
	if (num < static_cast<int>(std::numeric_limits<char>::min()
		|| num > static_cast<int>(std::numeric_limits<char>::max()))){
		return true;
	}
	return false;
}

/**
 * @return true: the input is a int type and won't overflow;
 *  false: the input is not a int type or it overflow.
 */
bool	ScalarConverter::isInt(const std::string& str, int& overflowFlag){
	try{
		size_t	pos;
		int num = std::stoi(str, &pos);
		bool isFullConvertion = (pos == str.length()); // checking if convert until the end
		if (isFullConvertion == true){
			if (isOverflowCharType(num) == true){
				overflowFlag |= CharOverflow;
			}
			return true;
		}
		return false;
	} catch (const std::out_of_range& e){
		overflowFlag |= IntOverflow;
		return false;
	} catch (const std::invalid_argument& e){
		return false;
	} catch (const std::exception& e){
		std::cerr << "ScalarConverter::isInt error: " << e.what() << std::endl;
		return false;
	}
}

bool	ScalarConverter::isFloat(const std::string& str, int& overflowFlag){
	size_t	length = str.length();

	// if the length of the str less than 4, it must be invalid.
	if (length < 4){
		return false;
	}

	//  there is no 'f' or 'f' is not at the end of the string, return false
	size_t	f_pos = str.find('f');
	if (f_pos == std::string::npos || f_pos != length){
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

	try {
		size_t	pos;
		std::stof(str, &pos);
		// return pos == length - 1;
		return true;
	} catch (const std::out_of_range& e){
		overflowFlag |= FloatOverflow;
		return false;
	}
}


bool	ScalarConverter::isDouble(const std::string& str, int& overflowFlag){
	// 1. checking if the format follows the doublt rules(contain only
	// digit and '.', and only contain one dot. It is not starting or ending
	// with the dot)

	size_t	length = str.length();
	// if the length of the str less than 3, it must be invalid.
	if (length < 3){
		return false;
	}
	size_t	i = 0;
	size_t	dot = str.find('.'); // the index of the first dot

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
		if (!(std::isdigit(static_cast<unsigned char>(str[i]))
			|| str[i] == '.')){
			return false;
		}
	}

	// 2. checking if it overflow double type
	try{
		size_t	pos;
		std::stod(str, &pos);
		return true;
	} catch (const std::out_of_range& e){
		overflowFlag |= DoubleOverflow;
		return false;
	}
}


bool	ScalarConverter::isPseudoFloat(const std::string& str){
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	return false;
}

bool	ScalarConverter::isPseudoDouble(const std::string& str){
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	return false;
}

/*--------------------------------Check Type-------------------------------*/

/**
 * @brief the function will check which type the passed string belong to,
 * and get the overflow information.
 */
Type	ScalarConverter::checkType(const std::string& str, int& overflowFlag){
	if (isChar(str)){
		return Type::Char;
	}else if(isInt(str, overflowFlag)){
		return Type::Int;
	}else if(isPseudoFloat(str)){
		return Type::PseudoFloat;
	}else if(isFloat(str, overflowFlag)){
		return Type::Float;
	}else if (isPseudoDouble(str)){
		return Type::PseudoDouble;
	}else if (isDouble(str, overflowFlag)){
		return Type::Double;
	}else {
		return Type::Unknow;
	}
}

/*--------------------------convertion functions-------------------------*/

void	ScalarConverter::convert(Type type, const std::string& str, char& c,
int& i, float& f, double& d){
	switch (type){
		case Type::Char:
			c = str[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		case Type::Int:
			i = std::stoi(str);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;
		case Type::PseudoFloat:
			f = std::stof(str);
			d = static_cast<double>(f);
			break ;
		case Type::Float:
			f = std::stof(str);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break ;
		case Type::PseudoDouble:
			d = std::stod(str);
			f = static_cast<float>(d);
			break ;
		case Type::Double:
			d = std::stod(str);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break ;
		default:
			std::cerr << "ScalarConverter::convert() error: unknow type\n";
	}
}

void	ScalarConverter::display(Type type, int overflowFlags, char c, int i,
float f, double d){
	// output char value
	if (type == Type::PseudoFloat || type == Type::PseudoDouble || overflowFlags > 0){
		std::cout << "char: impossible\n";
	} else if (std::isprint(static_cast<unsigned int>(c))){
		std::cout << "char: '" << c << "'\n";
	} else {
		std::cout << "char: Non displayable\n";
	}

	// output int value
	if (type == Type::PseudoFloat || type == Type::PseudoDouble || overflowFlags > 1){
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << i << "\n";
	}

	// output float value
	std::cout << std::fixed << std::setprecision(1);
	if (overflowFlags > 2){
		std::cout << "float: impossible\n";
	} else {
		std::cout << "float: " << f << "\n";
	}

	// output double value
	if (overflowFlags > 4){
		std::cout << "double: impossible\n";
	} else {
		std::cout << "double: " << d << "\n";
	}
}

void	ScalarConverter::convert(const std::string& str){
	if (str.empty()){
		std::cout << "Hey, friend! You didn't input anything\n";
		return ;
	}
	int	overflowFlag = 0;
	Type	type = checkType(str, overflowFlag);

	if (type == Type::Unknow){
		std::cout << "char: " << "impossbile\n";
		std::cout << "int: " << "impossbile\n";
		std::cout << "float: " << "impossbile\n";
		std::cout << "double: " << "impossbile\n";
		return ;
	}
	char	c = 0;
	int		i = 0;
	float	f = 0.0;
	double	d = 0.0;
	try{
		convert(type, str, c, i, f, d);
	} catch (const std::exception& e){
		std::cerr << "ScalarConverter::convert() error: " << e.what() << std::endl;
		return ;
	}
	display(type, overflowFlag, c, i, f, d);
}
