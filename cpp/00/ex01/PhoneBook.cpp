#include <iostream>
#include <string>

class PhoneBook{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void PhoneBook();
		void addContact();
		void searchContact();
};

void addContact(PhoneBook phoneBook){
	std::cout << "firstname: ";
	std::getline(std::cin, firstName);
}

void searchContact(){

}

void PhoneBook(){
	firstName = NULL;
	lastName = NULL;
	nickName = NULL;
	phoneNumber = NULL;
	darkestSecret = NULL;
}

int main(){
	std::string command;

	while (1)
	{
		std::cout << "command: ";
		if (std::getline(std::cin, command) == NULL)
			return 0;
		if (command == "EXIT")
			return 0;
		else if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContact();
	}
}
