/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:35:21 by daypark           #+#    #+#             */
/*   Updated: 2022/01/19 16:21:32 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::addOneContact()
{
	while (1)
	{
		std::cout << "Firstname: ";
		if (!std::getline(std::cin, first_name))
			break ;
		std::cout << "Lastname: ";
		if (!std::getline(std::cin, last_name))
			break ;
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, nick_name))
			break ;
		std::cout << "Phone Number: ";
		if (!std::getline(std::cin, phone_number))
			break ;
		std::cout << "Darkest Secret: ";
		if (!std::getline(std::cin, darkest_secret))
			break ;
		if (first_name.length() != 0 && last_name.length() != 0 && nick_name.length() != 0 && \
			phone_number.length() != 0 && darkest_secret.length() != 0)
		{
			std::cout << "Add Success!" << std::endl;
			break ;
		}
		std::cout << "Fill it again!" << std::endl;
	}
}
