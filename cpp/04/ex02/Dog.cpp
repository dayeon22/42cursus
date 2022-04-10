/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:46:01 by daypark           #+#    #+#             */
/*   Updated: 2022/04/10 17:19:39 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[Dog] Default constructor called" << std::endl;
	type_ = "Dog";
	brain_ = new Brain();
}

Dog::Dog(const Dog &dog) {
	std::cout << "[Dog] Copy constructor called" << std::endl;
	*this = dog;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
	delete brain_;
}

Dog &Dog::operator=(const Dog &dog) {
	type_ = dog.type_;
	brain_ = new Brain(*dog.brain_);
	return *this;
}

std::string Dog::getType() const {
	return type_;
}

void Dog::makeSound() const {
	std::cout << "bark" << std::endl;
}

Brain *Dog::getBrain() {
	return brain_;
}