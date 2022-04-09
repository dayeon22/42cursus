/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WorngAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:35:01 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 17:55:02 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	type_ = "WrongAnimal";
	std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
	type_ = wrongAnimal.type_;
	return *this;
}

std::string WrongAnimal::getType() const {
	return type_;
}

void WrongAnimal::makeSound() const {
	std::cout << "..." << std::endl;
}