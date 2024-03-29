/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:15 by daypark           #+#    #+#             */
/*   Updated: 2022/05/22 18:43:25 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
	name_ = name;
	weapon_ = weapon;
}

void HumanA::attack(){
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
