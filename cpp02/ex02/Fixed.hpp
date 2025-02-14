/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:25 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/13 10:43:25 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

#define EPSILON 1e-7

class Fixed{
	private:
		int					value_;
		static const int	fractional_bits_ = 8;
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& other);
		~Fixed();

		Fixed&	operator=(const Fixed& other);
		//6 comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// 4 arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// pre-increment and pre-decrement
		Fixed&	operator++();
		Fixed&	operator--();

		// post-increment and post-decrement
		Fixed	operator++(int);
		Fixed	operator--(int);

		// min and max
		static Fixed&	min(Fixed& x, Fixed& y);
		static const Fixed&	min(const Fixed& x, const Fixed& y);
		static Fixed&	max(Fixed& x, Fixed& y);
		static const Fixed&	max(const Fixed& x, const Fixed& y);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& number);

#endif // FIXED_HPP

/**
Why use keyword 'static' for min and max in the class?
1. No Need for an Instance
	Since min and max just compare two objects, there is no need for an instance of Fixed.
	You can call them directly on the class:
		{
			Fixed a(3.5f);
			Fixed b(4.2f);
			Fixed& smallest = Fixed::min(a, b); // No instance required!
		}

	Without static, you'd have to call min on an object:
		{
			a.min(b);  // ❌ Doesn't make sense, because min is not about "a", but about "a" and "b".
		}
	Making it static allows calling it without an instance.
2. Saves Memory & Avoids Unnecessary Objects
	A non-static member function would require an instance of Fixed to exist.
	A static function does not require an instance, reducing memory overhead.
 */
