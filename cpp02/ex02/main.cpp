/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:29 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/13 10:43:29 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

# if 1
int main( void ) {
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

#endif

# if 0
void testComparisonOperators(const Fixed& a, const Fixed& b) {
    std::cout << "Comparing " << a << " and " << b << ":\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a >= b: " << (a >= b) << "\n";
    std::cout << "a <= b: " << (a <= b) << "\n";
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
}

void testArithmeticOperators(const Fixed& a, const Fixed& b) {
    std::cout << "Arithmetic operations with " << a << " and " << b << ":\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n";
}

void testIncrementDecrement(Fixed a) {
    std::cout << "Testing increment and decrement on " << a << ":\n";
    std::cout << "Pre-increment: " << ++a << "\n";
    std::cout << "Post-increment: " << a++ << " (After: " << a << ")\n";
    std::cout << "Pre-decrement: " << --a << "\n";
    std::cout << "Post-decrement: " << a-- << " (After: " << a << ")\n";
}

void testMinMax(const Fixed& a, const Fixed& b) {
    std::cout << "Testing min/max with " << a << " and " << b << ":\n";
    std::cout << "Min: " << Fixed::min(a, b) << "\n";
    std::cout << "Max: " << Fixed::max(a, b) << "\n";
}

void testRawBits(Fixed& a) {
    std::cout << "Raw bits of " << a << ": " << a.getRawBits() << "\n";
    a.setRawBits(256);
    std::cout << "After setting raw bits: " << a.getRawBits() << "\n";
}

int main() {
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "Initial values:\n";
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
    std::cout << "d: " << d << " (Copy of b)\n";

    testComparisonOperators(b, c);
    testArithmeticOperators(b, c);
    testIncrementDecrement(b);
    testMinMax(b, c);
    testRawBits(a);

    return 0;
}
#endif
