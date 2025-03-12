#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <cfloat>
#include <cstdlib> // stoi()

/**
 * The key differences between enum and enum class:
 * 	Use enum class for better type safety and to avoid naming conflicts.
 *  Use enum only if you need implicit integer conversions or backward
 *  compatibility with older C++ code.
 */
enum class Type{
	Char,
	Int,
	Float,
	Double,
	PseudoFloat,
	PseudoDouble,
	Unknow,
	Empty
};

enum OverflowFlags{
	CharOverflow = 1,
	IntOverflow = 2,
	FloatOverflow = 4,
	DoubleOverflow = 8
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

		// static Type	getType(const std::string& str, int& overflowFlag);
		static bool	charOverFlowed(int c);
		static bool	isChar(const std::string& str);
		static bool	isInt(const std::string& str);
		static bool	isFloat(const std::string& str);
		static bool	isDouble(const std::string& str);
		static bool	isPseudoFloat(const std::string& str);
		static bool	isPseudoDouble(const std::string& str);

		static void	charConverter(const std::string& str);
		static void	intConverter(const std::string& str);
		static void	floatConverter(const std::string& str);
		static void	doubleConverter(const std::string& str);
		static void	pseudoFloatConverter(const std::string& str);
		static void	pesudoDoubleConverter(const std::string& str);

		static int	isOverflow(const double& num);
		static void	printChar(const char& c, bool overflow);
		// static void	cast(Type type, const std::string& str, char& c, int& i, float& f, double& d);
		// static bool	hasFlag(int flag, OverflowFlags);
		// static bool	displayData(Type type, int flag, char c, int i, float f, double d);
};