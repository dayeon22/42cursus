/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:35:18 by daypark           #+#    #+#             */
/*   Updated: 2022/05/11 17:01:28 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don't put enough! If you did I would not have to ak for it!" << std::endl << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming hrer for years and you just started working here last month." << std::endl << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level){
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*f[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	int i;
	for (i = 0; i < 4; i++){
		if (levels[i].compare(level) == 0)
			break;
	}
	switch(i){
		case 0:
			(this->*f[0])();
		case 1:
			(this->*f[1])();
		case 2:
			(this->*f[2])();
		case 3:
			(this->*f[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
	}
}
