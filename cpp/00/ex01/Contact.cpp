/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:35:21 by daypark           #+#    #+#             */
/*   Updated: 2022/05/10 15:00:20 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::addOneContact(){
	while (1)
	{
		std::cout << "Firstname: ";
		std::getline(std::cin, first_name);
		if (std::cin.fail())
			return ;
		std::cout << "Lastname: ";
		std::getline(std::cin, last_name);
		if (std::cin.fail())
			return ;
		std::cout << "Nickname: ";
		std::getline(std::cin, nick_name);
		if (std::cin.fail())
			return ;
		std::cout << "Phone Number: ";
		std::getline(std::cin, phone_number);
		if (std::cin.fail())
			return ;
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, darkest_secret);
		if (std::cin.fail())
			return ;
		if (first_name.length() != 0 && last_name.length() != 0 && nick_name.length() != 0 && \
			phone_number.length() != 0 && darkest_secret.length() != 0)
		{
			std::cout << "Add Success!" << std::endl;
			break ;
		}
		std::cout << "Fill it again!" << std::endl;
	}
}

void Contact::printOneContact(){
	std::cout << "Firstname: " << this->first_name << std::endl;
	std::cout << "Lastname: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nick_name << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}

void Contact::printAlign(std::string str){
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << "|";
}

void Contact::printRow(){
	printAlign(this->first_name);
	printAlign(this->last_name);
	printAlign(this->nick_name);
	std::cout << std::endl;
}
