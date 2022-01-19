/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:35:40 by daypark           #+#    #+#             */
/*   Updated: 2022/01/19 16:55:17 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	total = 0;
}

void PhoneBook::addContact(){
	this->contacts[total % 8].addOneContact();
	total++;
}

void PhoneBook::displayContact(){
	int max = total;
	
	if (max > 8)
		max = 8;
	for (int i = 0; i < max; i++)
	{
		this->contacts[i].printOneContact();
	}
}

int main(){
	PhoneBook phoneBook;
	std::string command;
	
	while (1)
	{
		std::cout << "command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			return 0;
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.displayContact();
		if (std::cin.fail())
			return 0;
	}
	return 0;
}
