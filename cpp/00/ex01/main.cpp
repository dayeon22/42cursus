/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:00:47 by daypark           #+#    #+#             */
/*   Updated: 2022/05/10 14:40:58 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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