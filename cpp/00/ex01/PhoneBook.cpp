/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:35:40 by daypark           #+#    #+#             */
/*   Updated: 2022/01/21 16:38:06 by daypark          ###   ########.fr       */
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
	int index;
	
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|   index  |first name| last name| nickname |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (max > 8)
		max = 8;
	for (int i = 0; i < max; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		this->contacts[i].printOneContact();
	}
	while (1)
	{
		std::cout << "index: ";
		std::cin >> index;

		if (0 <= index && index < max)
		{
			//printcontact();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 디펜스
			break ;
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	}
}

int main(){ //main.cpp 파일 만들어서 넣기!!
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
	}
	return 0;
}
