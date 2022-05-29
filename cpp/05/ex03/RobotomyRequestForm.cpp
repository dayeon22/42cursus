/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:06:04 by daypark           #+#    #+#             */
/*   Updated: 2022/05/29 18:02:00 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form() {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy request", target, 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rr) : 
Form(rr.getName(), rr.getTarget(), rr.getSignGrade(), rr.getExecuteGrade()) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rr) {
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	
    srand((unsigned int)time(NULL));
    int robo = rand() % 2;
    std::cout << "drrrrrrrr..." << std::endl;
    if (!robo)
        throw RobotomizeFailedException();
    else
        std::cout << getTarget() << " has been robotomized." << std::endl;
}

const char *RobotomyRequestForm::RobotomizeFailedException::what() const throw() {
    return "Exception: RobotomizeFailedException";
}