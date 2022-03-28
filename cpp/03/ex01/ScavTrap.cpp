/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:44:31 by daypark           #+#    #+#             */
/*   Updated: 2022/03/28 13:53:57 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints_ = 100;
	energePoints_ = 50;
	attackDamage_ = 20;
	std::cout << "Scavtrap [" << name_ << "]" << "is created by default constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hitPoints_ = 100;
	energePoints_ = 50;
	attackDamage_ = 20;
	std::cout << "Scavtrap [" << name_ << "]" << "is created by constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	*this = scavTrap;
	std::cout << "Scavtrap [" << name_ << "]" << "is copied." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scavtrap [" << name_ << "]" << "is deleted." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
	std::cout << "Operator '=' called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (hitPoints_ <= 0 || energePoints_ <= 0) {
		std::cout << "Scavtrap [" << name_ << "]" << "cannot do anything." << std::endl;
		return ;
	}
	energePoints_--;
	std::cout << "Scavtrap [" << name_ << "]" << "attacks " << target << " causing " << attackDamage_ << " points of damage." << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "Scavtrap [" << name_ << "]" << "is now in Gate keeper mode." << std::endl;
}