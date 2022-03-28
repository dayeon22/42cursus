/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:02:19 by daypark           #+#    #+#             */
/*   Updated: 2022/03/28 15:48:03 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints_(10), energePoints_(10), attackDamage_(0) {
	name_ = "claptrap";
	std::cout << "Claptrap [" << name_ << "] is created by default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hitPoints_(10), energePoints_(10), attackDamage_(0) {
	name_ = name;
	std::cout << "Claptrap [" << name_ << "] is created by constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	*this = clapTrap;
	std::cout << "Claptrap [" << name_ << "] is copied." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap [" << name_ << "] is deleted." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	name_ = clapTrap.name_;
	hitPoints_ = clapTrap.hitPoints_;
	energePoints_ = clapTrap.energePoints_;
	attackDamage_ = clapTrap.attackDamage_;
	std::cout << "Claptrap Operator '=' called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (hitPoints_ <= 0 || energePoints_ <= 0) {
		std::cout << "Claptrap [" << name_ << "] cannot do anything." << std::endl;
		return ;
	}
	energePoints_--;
	std::cout << "Claptrap [" << name_ << "] attacks " << target << " causing " << attackDamage_ << " points of damage." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints_ <= 0) {
		std::cout << "Claptrap [" << name_ << "] is already dead." << std::endl;
	}
	if (hitPoints_ <= amount) {
		hitPoints_ = 0;
		std::cout << "Claptrap [" << name_ << "] dies." << std::endl;
		return ;
	}
	hitPoints_ -= amount;
	std::cout << "Claptrap [" << name_ << "] is damaged " << amount << " hit point." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints_ <= 0 || energePoints_ <= 0) {
		std::cout << "Claptrap [" << name_ << "] cannot do anything." << std::endl;
		return ;
	}
	energePoints_--;
	hitPoints_ += amount;
	std::cout << "Claptrap [" << name_ << "] repairs " << amount << " hit point." << std::endl;
}