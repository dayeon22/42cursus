/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:49:54 by daypark           #+#    #+#             */
/*   Updated: 2021/12/26 16:31:10 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class PhoneBook{
	private:
		int index;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void addContact(int index){
			while (1)
			{
				std::cout << "Firstname: ";
				if (std::getline(std::cin, firstName) == NULL)
					break ;
				std::cout << "Lastname: ";
				if (std::getline(std::cin, lastName) == NULL)
					break ;
				std::cout << "Nickname: ";
				if (std::getline(std::cin, nickName) == NULL)
					break;
				std::cout << "Phone Number: ";
				if (std::getline(std::cin, phoneNumber) == NULL)
					break;
				std::cout << "Darkest Secret: ";
				if (std::getline(std::cin, darkestSecret) == NULL)
					break;
				if (firstName.length() != 0 && lastName.length() != 0 && nickName.length() != 0 && phoneNumber.length() != 0 && darkestSecret.length() != 0)
				{
					this->index = index; //이렇게 쓰는거 맞나?
					std::cout << "Add Success!" << std::endl;
					break ;
				}
				std::cout << "Fill it again!" << std::endl;
			}
		}
		void displayContacts()
		{
			std::cout << index;
			std::cout << firstName;
			std::cout << lastName;
			std::cout << nickName;
			std::cout << std::endl;
		}
};

int main(){
	PhoneBook phoneBook[8];
	std::string command;
	int index = 0;

	while (1)
	{
		std::cout << "command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			return 0;
		else if (command == "ADD")
		{
			phoneBook[index].addContact(index);
			//index + 1 % 8이 있으면 소멸자로 소멸해줘야 함
			index = (index + 1) % 8;
		}
		else if (command == "SEARCH")
		{
			for (int i = 0; i < 8; i++)
			{
				phoneBook[i].displayContacts();
			}
		}
		if (std::cin.fail())
			return 0;
	}
}
