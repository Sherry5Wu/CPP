#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>

class Fixed{
	private:
		int					value_;
		static const int	fractional_bits_ = 8;
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &newValue);
		Fixed	&operator=(const Fixed &newValue);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream	&operator << (std::ostream &outputStream, const Fixed &number);

#endif // FIXED_HPP