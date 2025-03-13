/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:43:43 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/13 14:43:43 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits> // std::numeric_limits<char>::min, std::numeric_limits<char>::max
#include <limits.h>
#include <cmath>
#include <cfloat>
#include <cstdlib> // stoi()
#include <ios> // std::fixed
#include <iomanip> // std::setprecision

/**
 * The key differences between enum and enum class:
 * 	Use enum class for better type safety and to avoid naming conflicts.
 *  Use enum only if you need implicit integer conversions or backward
 *  compatibility with older C++ code.
 */
enum class Type{
	Unknow = 0,
	Char = 1,
	Int = 2,
	Float = 3,
	Double = 4,
	PseudoFloat = 5,
	PseudoDouble = 6
};

enum OverflowType{
	CharOverflow = 1, // binary represent is: 0001
	IntOverflow = 2,  // binary represent is: 0010
	FloatOverflow = 4,// binary represent is: 0100
	DoubleOverflow = 8// binary represent is: 1000
};

class ScalarConverter{
	public:
		static void	convert(const std::string& str);

	// all the constructors are private, so the class can't be instanciable.
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter& other);

		// static bool	charOverFlowed(int c);
		static bool	isChar(const std::string& str);
		static bool	isInt(const std::string& str, int& overflowFlag);
		static bool	isFloat(const std::string& str, int& overflowFlag);
		static bool	isDouble(const std::string& str, int& overflowFlag);
		static bool	isPseudoFloat(const std::string& str);
		static bool	isPseudoDouble(const std::string& str);

		// static void	charConverter(const std::string& str);
		// static void	intConverter(const std::string& str);
		// static void	floatConverter(const std::string& str);
		// static void	doubleConverter(const std::string& str);
		// static void	pseudoFloatConverter(const std::string& str);
		// static void	pesudoDoubleConverter(const std::string& str);

		// static int	isOverflow(const double& num);
		static bool	isOverflowCharType(int num);
		// static void	printChar(const char& c, bool overflow);
		static Type	checkType(const std::string& str, int& overflowFlag);
		static void	convert(Type type, const std::string& str, char& c, int& i, float& f, double& d);
		static void	display(Type type, int overflowFlags, char c, int i, float f, double d);
		// static bool	isTheTypeOverflow(int overflowFlags, int overflowType);
};
