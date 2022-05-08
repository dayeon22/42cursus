/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:06:04 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 02:09:15 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, "SC", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &sc) : 
Form(sc.getTarget(), sc.getType(), sc.getSignGrade(), sc.getExecuteGrade()) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &sc) {
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	// if (getIsSigned() == true)
	// 	std::cout
	if (getIsSigned() == false || executor.getGrade() > getExecuteGrade())
		throw CannotExecuteException();
}