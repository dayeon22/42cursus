/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:15 by daypark           #+#    #+#             */
/*   Updated: 2022/02/13 15:34:09 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	name_ = name;
}

void HumanB::setWeapon(Weapon &weapon){
	weapon_ = &weapon;
}

void HumanB::attack(){
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}