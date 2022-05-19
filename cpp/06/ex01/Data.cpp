/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 07:27:02 by daypark           #+#    #+#             */
/*   Updated: 2022/05/20 07:55:01 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : name_("daypark"), age_(25) {

}

Data::Data(std::string name, int age) : name_(name), age_(age) {

}

Data::Data(const Data &data) {
	*this = data;
}

Data::~Data() {

}

Data &Data::operator=(const Data &data) {
	name_ = data.name_;
	age_ = data.age_;
	return *this;
}

std::string Data::getName() const {
	return name_;
}

int Data::getAge() const {
	return age_;
}

std::ostream &operator<<(std::ostream &outputStream, const Data &data) {
	std::cout << data.getName() << ", " << data.getAge();
	return outputStream;
}