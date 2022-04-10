/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:46:01 by daypark           #+#    #+#             */
/*   Updated: 2022/04/10 17:04:52 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type_ = "Dog";
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	std::cout << "[Dog] Copy constructor called" << std::endl;
	*this = dog;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
	type_ = dog.type_;
	return *this;
}

std::string Dog::getType() const {
	return type_;
}

void Dog::makeSound() const {
	std::cout << "bark" << std::endl;
}