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
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// 4 arithmetic operators
		Fixed&	operator+(const Fixed& other) const;
		Fixed&	operator-(const Fixed& other) const;
		Fixed&	operator*(const Fixed& other) const;
		Fixed&	operator/(const Fixed& other) const;

		// pre-increment and pre-decrement
		Fixed&	operator++();
		Fixed&	operator--();

		// post-increment and post-decrement
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&	min(Fixed& x, Fixed& y);
		static Fixed&	min(const Fixed& x, const Fixed& y);
		static Fixed&	max(Fixed& x, Fixed& y);
		static Fixed&	max(const Fixed& x, const Fixed& y);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& number);

#endif // FIXED_HPP
