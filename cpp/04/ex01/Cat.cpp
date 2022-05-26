/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:28:34 by daypark           #+#    #+#             */
/*   Updated: 2022/05/26 15:36:20 by daypark          ###   ########.fr       */
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
	brain_ = NULL;
	*this = cat;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
	delete brain_;
}

Cat &Cat::operator=(const Cat &cat) {
	type_ = cat.type_;
	if (brain_)
		delete brain_;
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