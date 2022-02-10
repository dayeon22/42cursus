/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:40:03 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 15:13:27 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	type_ = type;
}

std::string Weapon::getType(){
	return type_;
}

void Weapon::setType(std::string type){
	type_ = type;
}
