/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:35:36 by daypark           #+#    #+#             */
/*   Updated: 2022/01/19 16:21:13 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int total;  // 총 인원
	// int index;  // 새로 입력할 위치 인덱스(추가하던지 말던지)
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void displayContact();
};

#endif
