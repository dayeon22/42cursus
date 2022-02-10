/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:15 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 15:18:40 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName){
	humanName_ = humanName;
}

void HumanB::setWeapon(Weapon &weapon){
	weaponType_ = weapon.getType();
}

void HumanB::attack(){
	std::cout << humanName_ << " attacks with his " << weaponType_ << std::endl;
}
