/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:57:34 by daypark           #+#    #+#             */
/*   Updated: 2022/03/21 15:20:28 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value_;
	const static int bits_ = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed (const Fixed &fixed);
	~Fixed();

	Fixed &operator=(const Fixed &fixed);
	bool operator>(const Fixed &fixed);
	bool operator<(const Fixed &fixed);
	bool operator>=(const Fixed &fixed);
	bool operator<=(const Fixed &fixed);
	bool operator==(const Fixed &fixed);
	bool operator!=(const Fixed &fixed);
	Fixed operator+(const Fixed &fixed);
	Fixed operator-(const Fixed &fixed);
	Fixed operator*(const Fixed &fixed);
	Fixed operator/(const Fixed &fixed);
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed const &min(const Fixed &one, const Fixed &two);
	static Fixed const &max(const Fixed &one, const Fixed &two);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator<<(std::ostream &outputStream, const Fixed &fixed);

#endif
