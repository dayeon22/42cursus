/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:54:14 by daypark           #+#    #+#             */
/*   Updated: 2022/05/05 18:14:29 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : target_("default"), isSigned_(false), signGrade_(150), executeGrade_(150) {

}

Form::Form(std::string target, std::string type_, int signGrade, int executeGrade) : 
    target_(target), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade) {
    checkGrade();
}

Form::Form(const Form &form) : target_(form.target_), isSigned_(form.isSigned_), signGrade_(form.signGrade_), executeGrade_(form.executeGrade_) {

}

Form::~Form() {

}

Form &Form::operator=(const Form &form) {
    return *this;
}

std::string Form::getTarget() const {
    return target_;
}

std::string Form::getType() const {
    return type_;
}

bool Form::getIsSigned() const {
    return isSigned_;
}

int Form::getSignGrade() const {
    return signGrade_;
}

int Form::getExecuteGrade() const {
    return executeGrade_;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (executeGrade_ < bureaucrat.getGrade())
        throw GradeTooLowException();
    else
        isSigned_ = true;
}

void Form::checkGrade() {
    if (signGrade_ < 1 || executeGrade_ < 1)
        throw GradeTooHighException();
    else if (signGrade_ > 150 || executeGrade_ > 150)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outputStream, const Form &form) {
    std::cout << "name: " << form.getTarget() << ", is signed: " << form.getIsSigned() << ", grade: " 
    << form.getSignGrade() << ", required grade: " << form.getExecuteGrade();
    return outputStream;
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Exception: GradeTooLowException";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Exception: GradeTooHighException";
}

const char *Form::CannotExecuteException::what() const throw() {
    return "Exception: CannotExecuteException";
}