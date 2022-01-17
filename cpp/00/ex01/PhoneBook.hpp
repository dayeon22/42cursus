/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:12:42 by daypark           #+#    #+#             */
/*   Updated: 2022/01/15 18:20:03 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

class PhoneBook{
	private:
		Contact contacts[8];
		int number_of_contact;
	public:
		void addContact();
		void displayContact(Contact contacts[]); //매개변수 이런식으로 하는게 맞는지
}

#endif
