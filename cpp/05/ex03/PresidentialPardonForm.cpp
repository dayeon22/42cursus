/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:06:04 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 18:06:30 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form() {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("presidnetial pardon", target, 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pp) : 
Form(pp.getName(), pp.getTarget(), pp.getSignGrade(), pp.getExecuteGrade()) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &pp) {
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
