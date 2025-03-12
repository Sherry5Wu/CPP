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
/**
 * @brief how to check if the passed str is a char?
 *  1. the lenght of the str is 1;
 *  2. the character is not a digit;
 *  3. the character is printable.
 *
 * Why convert str to unsigned char type?
 *  isdigit is expecting a unsigned char type value. If we don't convert it,
 *  it might cause some undefined error.
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

bool	ScalarConverter::isInt(const std::string& str){
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

bool	ScalarConverter::isDouble(const std::string& str){
	size_t	length = str.length();

	// if the length of the str less than 3, it must be invalid.
	if (length < 3){
		return false;
	}

	size_t	i = 0;
	size_t	dot = str.find('.'); // the index of the first dot

	// Here to make sure it only contains one dot and the dot isn't at the end
	if (dot == std::string::npos || str.find('.', (dot + 1)) != std::string::npos){
		return false;
	}

	if ((str[i] == '-' || str[i] == '+') && str.length() > 2)
		i++;
	for (; i < str.length(); i++){
		if (!(std::isdigit(static_cast<unsigned char>(str[i])) || str[i] == '.')){
			return false;
		}
	}
	return true;
}

bool	ScalarConverter::isFloat(const std::string& str){
	size_t	length = str.length();

	// if the length of the str less than 4, it must be invalid.
	if (length < 4){
		return false;
	}
	if (isDouble(str.substr(0, length - 1)) && str[length - 1] == 'f'){
		return true;
	}
	return false;
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
int	ScalarConverter::isOverflow(const double& num){
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
void	ScalarConverter::printChar(const char& c, bool overflow){
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

void	ScalarConverter::charConverter(const std::string& str){
	std::cout << "char: " << "'" << str[0] << "'\n";
	std::cout << "int: " << static_cast<int>(str[0]) << "\n";
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f\n";
	std::cout << "double: " << static_cast<double>(str[0]) << ".0\n";
}

void	ScalarConverter::intConverter(const std::string& str){
	size_t	pos;
	double	num = std::stod(str, &pos);
	int		overflow = ScalarConverter::isOverflow(num);

	// output char info
	ScalarConverter::printChar(static_cast<char>(num), overflow);
	// output int info
	if (overflow < 2){
		std::cout << "int: " << static_cast<int>(num) <<"\n";
	}else{
		std::cout << "int: impossible\n";
	}
	// output float info
	if (overflow < 2){
		std::cout << "float: " << static_cast<float>(num) <<".0f\n";
	}else{
		std::cout << "float: impossible\n";
	}
	// output dobule info
	std::cout << "double: " << num << std::endl;
}

void	ScalarConverter::floatConverter(const std::string& str){

}

void	ScalarConverter::doubleConverter(const std::string& str){

}

void	ScalarConverter::pseudoFloatConverter(const std::string& str){

}

void	ScalarConverter::pesudoDoubleConverter(const std::string& str){

}


void	ScalarConverter::convert(const std::string& str){
	bool	(*checkers[6])(const std::string& str) = {&ScalarConverter::isChar,
													  &ScalarConverter::isInt,
													  &ScalarConverter::isFloat,
													  &ScalarConverter::isDouble,
													  &ScalarConverter::isPseudoFloat,
													  &ScalarConverter::isPseudoDouble};

	void	(*converter[6])(const std::string& str) = {&ScalarConverter::charConverter,
													   &ScalarConverter::intConverter,
													   &ScalarConverter::floatConverter,
													   &ScalarConverter::doubleConverter,
													   &ScalarConverter::pseudoFloatConverter,
													   &ScalarConverter::pesudoDoubleConverter};
	for (int i = 0; i < 6; i++){
		// if checkers[i] is true, then it means the str doesn't contain any invalid chararcters.
		if (checkers[i](str)){
			std::size_t	pos;

			// checking if the str is out of double range.
			try{
				double	num = std::stod(str, &pos);
				(void)num;
				return converter[i](str);
			}catch (const std::out_of_range& e){
				std::cout << "char: " << "impossbile\n";
				std::cout << "int: " << "impossbile\n";
				std::cout << "float: " << "impossbile\n";
				std::cout << "double: " << "impossbile\n";
			}
		}
	}
	std::cout << "Error: invaid input" << std::endl;
}