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
		static const int	fractional_bits_ = 8; // it means how many bits to
		// represent the fractional part. Here it means in the value_ , the
		// lower 8 bits represent fractional part.
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& number);

#endif // FIXED_HPP
