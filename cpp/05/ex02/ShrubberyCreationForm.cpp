/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:06:04 by daypark           #+#    #+#             */
/*   Updated: 2022/05/03 17:44:30 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm) : 
Form(shrubberyCreationForm.getTarget(), shrubberyCreationForm.getSignGrade(), shrubberyCreationForm.getExecuteGrade()) {
//이거맞나?
//이건 새 객체 생성하는것 같은데...
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm) {
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	
}