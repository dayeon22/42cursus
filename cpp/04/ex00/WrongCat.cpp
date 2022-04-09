/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:37:36 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 17:38:58 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type_ = "WrongCat";
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	*this = wrongCat;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
	type_ = wrongCat.type_;
	return *this;
}

std::string WrongCat::getType() const {
	return type_;
}

void WrongCat::makeSound() const {
	std::cout << "meow" << std::endl;
}