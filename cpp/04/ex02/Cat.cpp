/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:28:34 by daypark           #+#    #+#             */
/*   Updated: 2022/04/10 17:15:03 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[Cat] Default constructor called" << std::endl;
	type_ = "Cat";
	brain_ = new Brain();
}

Cat::Cat(const Cat &cat) {
	std::cout << "[Cat] Copy constructor called" << std::endl;
	*this = cat;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
	delete brain_;
}

Cat &Cat::operator=(const Cat &cat) {
	type_ = cat.type_;
	brain_ = new Brain(*cat.brain_);
	return *this;
}

std::string Cat::getType() const {
	return type_;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}

Brain *Cat::getBrain() {
	return brain_;
}