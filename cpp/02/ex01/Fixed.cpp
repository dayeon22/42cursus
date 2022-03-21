/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:07:18 by daypark           #+#    #+#             */
/*   Updated: 2022/03/21 15:21:47 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value_ = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	value_ = value << bits_;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	value_ = roundf(value * (1 << bits_));
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &fixed) {
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const {
	return value_;
}

void Fixed::setRawBits(int const raw) {
	value_ = raw;
}

float Fixed::toFloat(void) const {
	return (float(value_) / (1 << bits_));
}

int Fixed::toInt(void) const {
	return (value_ >> bits_);
}

std::ostream & operator<<(std::ostream &outputStream, const Fixed &fixed) {
	std::cout << fixed.toFloat();
	return outputStream;
}
