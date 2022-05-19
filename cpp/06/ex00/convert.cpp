/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:53:45 by daypark           #+#    #+#             */
/*   Updated: 2022/05/20 02:35:10 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {

}

Convert::Convert(std::string &str) {
	str_ = str;
}

Convert::Convert(const Convert &convert) {
	*this = convert;
}

Convert::~Convert() {

}

Convert &Convert::operator=(const Convert &convert) {
	str_ = convert.str_;
	return *this;
}

void Convert::convertToScalar() {
	try {
		convertToChar();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		convertToInt();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		convertToFloat();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		convertToDouble();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void Convert::convertToChar() {
	int num = 0;
	
	std::cout << "char: ";
	try {
		num = stoi(str_);
	} catch (std::exception &e) {
		throw ImpossibleException();
	}
	if (!std::isprint(num))
		throw NonDisplayableException();
	std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
}

void Convert::convertToInt() {
	int num;

	std::cout << "int: ";
	try {
		num = stoi(str_);
	} catch (std::exception &e) {
		throw ImpossibleException();
	}
	if (isnan(num) || isinf(num) || num > 2147483647 || num < -2147483648)
		throw ImpossibleException();
	std::cout << num << std::endl;
}

void Convert::convertToFloat() {
	float num = stof(str_);

	std::cout << "float: ";
	std::cout << num;
	if (num - static_cast<int>(num) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void Convert::convertToDouble() {
	double num = stod(str_);

	std::cout << "double: ";
	std::cout << num;
	if (num - static_cast<int>(num) == 0)
		std::cout << ".0";
}

const char *Convert::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

const char *Convert::ImpossibleException::what() const throw() {
	return "impossible";
}