/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:40:03 by daypark           #+#    #+#             */
/*   Updated: 2022/02/13 16:00:43 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	type_ = type;
}

const std::string Weapon::getType(){
	return type_;
}

void Weapon::setType(const std::string type){
	type_ = type;
}
