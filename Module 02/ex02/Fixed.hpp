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

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		
		static Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

	private:
		int					_value;
		static const int	_fractional_bits;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
