/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/06 18:29:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator = (const Fixed &other);
		~Fixed();
		
		bool 	operator > (const Fixed &other) const;
		bool	operator < (const Fixed &other) const;
		bool 	operator >= (const Fixed &other) const;
		bool 	operator <= (const Fixed &other) const;
		bool 	operator == (const Fixed &other) const;
		bool 	operator != (const Fixed &other) const;
		
		Fixed	operator + (const Fixed &other) const;
		Fixed	operator - (const Fixed &other) const;
		Fixed	operator * (const Fixed &other) const;
		Fixed	operator / (const Fixed &other) const;

		Fixed	operator ++ (int);  // i++
		Fixed	operator -- (int);  // i--
		Fixed	&operator ++ (void);  // ++i
		Fixed	&operator -- (void); // --i

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);

		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif