#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int ivalue);
		Fixed(const float fvalue);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		

	private:
		int					_value;
		static const int	_fractional_bits;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
