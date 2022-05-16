/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:31:05 by daypark           #+#    #+#             */
/*   Updated: 2022/05/17 07:57:06 by daypark          ###   ########.fr       */
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
	(void)intern;
	return *this;
}

Form *Intern::makeForm(std::string name, std::string target) {
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *(Intern::*f[4])(std::string) = {&Intern::makeSCForm, &Intern::makeRRForm, &Intern::makePPForm};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			return (this->*f[i])(target);
		}
	}
	throw WrongFormName();
}

Form *Intern::makeSCForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeRRForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form *Intern::makePPForm(std::string target) {
	return new PresidentialPardonForm(target);
}

const char *Intern::WrongFormName::what() const throw() {
	return "Exception: WrongFormNameExcpetion";
}