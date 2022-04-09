/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:28:34 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 17:25:19 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type_ = "Cat";
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
	std::cout << "[Cat] Copy constructor called" << std::endl;
	*this = cat;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
	type_ = cat.type_;
	return *this;
}

std::string Cat::getType() const {
	return type_;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}