/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:35:40 by daypark           #+#    #+#             */
/*   Updated: 2022/01/22 19:27:06 by daypark          ###   ########.fr       */
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
		this->contacts[i].printRow();
	}
	std::cout << "---------------------------------------------" << std::endl;
	while (1)
	{
		std::cout << "index: ";
		std::cin >> index;

		if (std::cin.fail())
		{
			std::cout << "wrong input!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
		if (0 <= index && index < max)
		{
			this->contacts[index].printOneContact();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 디펜스
			return ;
		}
		std::cout << "input the number between 0 to " << max - 1 << std::endl;
	}
}
