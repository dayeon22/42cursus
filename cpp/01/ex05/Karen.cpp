/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:02:19 by daypark           #+#    #+#             */
/*   Updated: 2022/03/07 15:58:30 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void Karen::debug(void){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl << std::endl;
}

void Karen::info(void){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don't put enough! If you did I would not have to ak for it!" << std::endl << std::endl;
}

void Karen::warning(void){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming hrer for years and you just started working here last month." << std::endl << std::endl;
}

void Karen::error(void){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void Karen::complain(std::string level){
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Karen::*f[4])(void) = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error };

	for (int i = 0; i < 4; i++){
		if (levels[i].compare(level) == 0){
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Cannot find level " << level << std::endl;
}
