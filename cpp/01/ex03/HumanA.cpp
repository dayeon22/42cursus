/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:15 by daypark           #+#    #+#             */
/*   Updated: 2022/02/12 16:38:08 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon &weapon) : weapon_(weapon){
	humanName_ = humanName;
	weapon_ = weapon;
}

void HumanA::attack(){
	std::cout << humanName_ << " attacks with his " << weapon_.getType() << std::endl;
}
