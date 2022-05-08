/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:31:05 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 19:27:20 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

Intern::~Intern() {

}

Intern &Intern::operator=(const Intern &intern) {
	return *this;
}

Form *Intern::makeForm(std::string name, std::string target) {
	Form *form;
	std::string names[3] = {"shrubbery creatioin", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name)
			//몰라
	}
	if (name == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (name == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (name == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else
		//예외처리...
	return form;
}