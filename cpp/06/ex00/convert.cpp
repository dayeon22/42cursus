/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayeon <daypark@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:43:31 by dayeon            #+#    #+#             */
/*   Updated: 2022/05/17 19:35:23 by dayeon           ###   ########.fr       */
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

void Convert::convertTo() {
	convertToChar();
	convertToInt();
	convertToFloat();
	convertToDouble();
}

void Convert::convertToChar() {
	std::cout << "char: ";
	std::cout << std::endl;
}

void Convert::convertToInt() {
	int num;

	num = stoi(str_);
	// int형을 float형으로 변환해야 함(static cast)
	//if (isnan(num)) 이런식으로 하기!
	std::cout << "int: ";
	std::cout << stoi(str_) << std::endl;
}

void Convert::convertToFloat() {
	std::cout << "float: ";
	std::cout << stof(str_) << std::endl;
}

void Convert::convertToDouble() {
	std::cout << "double: ";
	std::cout << stod(str_) << std::endl;
}
