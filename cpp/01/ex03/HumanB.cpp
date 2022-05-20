/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:15 by daypark           #+#    #+#             */
/*   Updated: 2022/05/20 13:47:10 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	name_ = name;
	weapon_ = NULL;
}

void HumanB::setWeapon(Weapon &weapon){
	weapon_ = &weapon;
}

void HumanB::attack(){
	if (weapon_ == NULL)
		std::cout << name_ << " doesn't have a weapon." << std::endl;
	else
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}
