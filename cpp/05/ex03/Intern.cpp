/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:31:05 by daypark           #+#    #+#             */
/*   Updated: 2022/05/17 07:24:04 by daypark          ###   ########.fr       */
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
	Form *form;
	std::string names[3] = {"shrubbery creatioin", "robotomy request", "presidential pardon"};
	Form *(Intern::*f[4])(std::string) = {&makeSCForm, &makeRRForm, &makePPForm};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			form = (this->*f[i])(target);
		}
	}
	// if (name == "shrubbery creation")
	// 	form = new ShrubberyCreationForm(target);
	// else if (name == "robotomy request")
	// 	form = new RobotomyRequestForm(target);
	// else if (name == "presidential pardon")
	// 	form = new PresidentialPardonForm(target);
	// else
	// 	//예외처리...
	return form;
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