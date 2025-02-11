#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int					value_;
		static const int	fractional_bits_ = 8;
	public:
		Fixed();
		Fixed(const Fixed &newValue);
		Fixed	&operator=(const Fixed &newValue);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif // FIXED_HPP