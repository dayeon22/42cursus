/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:35:40 by daypark           #+#    #+#             */
/*   Updated: 2022/01/19 15:59:33 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
	this->contacts[total % 8].addOneContact(); //total를 0으로 초기화 해줘야함(phonebook 생성자에서?)
	total++;
}

void PhoneBook::displayContact()
{
	
}

int main()
{
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
