/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:15:54 by daypark           #+#    #+#             */
/*   Updated: 2022/03/28 15:48:21 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hitPoints_ = 100;
	energePoints_ = 100;
	attackDamage_ = 30;
	std::cout << "FragTrap [" << name_ << "] is created by default constructor." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hitPoints_ = 100;
	energePoints_ = 100;
	attackDamage_ = 30;
	std::cout << "FragTrap [" << name_ << "] is created by constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	*this = fragTrap;
	std::cout << "FragTrap [" << name_ << "] is copied." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap [" << name_ << "] is deleted." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap) {
	std::cout << "FragTrap Operator '=' called" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string &target) {
	if (hitPoints_ <= 0 || energePoints_ <= 0) {
		std::cout << "FragTrap [" << name_ << "] cannot do anything." << std::endl;
		return ;
	}
	energePoints_--;
	std::cout << "FragTrap [" << name_ << "] attacks " << target << " causing " << attackDamage_ << " points of damage." << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "Fragtrap [" << name_ << "] highFive!!" << std::endl;
}