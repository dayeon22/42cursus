/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:07:18 by daypark           #+#    #+#             */
/*   Updated: 2022/05/22 18:26:33 by daypark          ###   ########.fr       */
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

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) {
	return value_ > fixed.value_;
}

bool Fixed::operator<(const Fixed &fixed) {
	return value_ < fixed.value_;
}

bool Fixed::operator>=(const Fixed &fixed) {
	return value_ >= fixed.value_;
}

bool Fixed::operator<=(const Fixed &fixed) {
	return value_ <= fixed.value_;
}

bool Fixed::operator==(const Fixed &fixed) {
	return value_ == fixed.value_;
}

bool Fixed::operator!=(const Fixed &fixed) {
	return value_ != fixed.value_;
}

Fixed Fixed::operator+(const Fixed &fixed) {
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) {
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) {
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) {
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
	value_++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	value_++;
	return temp;
}

Fixed &Fixed::operator--() {
	value_--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	value_--;
	return temp;
}

Fixed &Fixed::min(Fixed &one, Fixed &two) {
	if (one.value_ < two.value_)
		return one;
	return two;
}

const Fixed &Fixed::min(const Fixed &one, const Fixed &two) {
	if (one.value_ < two.value_)
		return one;
	return two;
}

Fixed &Fixed::max(Fixed &one, Fixed &two) {
	if (one.value_ > two.value_)
		return one;
	return two;
}

const Fixed &Fixed::max(const Fixed &one, const Fixed &two) {
	if (one.value_ > two.value_)
		return one;
	return two;
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

std::ostream &operator<<(std::ostream &outputStream, const Fixed &fixed) {
	std::cout << fixed.toFloat();
	return outputStream;
}
