/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:15:18 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 17:24:43 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	type_ = "Animal";
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cout << "[Animal] Copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
	type_ = animal.type_;
	return *this;
}

std::string Animal::getType() const {
	return type_;
}

void Animal::makeSound() const {
	std::cout << "..." << std::endl;
}
