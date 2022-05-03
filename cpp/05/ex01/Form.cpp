/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:54:14 by daypark           #+#    #+#             */
/*   Updated: 2022/05/03 11:51:00 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name_("default"), isSigned_(false), grade_(150), requiredGrade_(150) {

}

Form::Form(std::string name, int grade, int requiredGrade) : 
    name_(name), isSigned_(false), grade_(grade), requiredGrade_(requiredGrade) {
    checkGrade();
}

Form::Form(const Form &form) : name_(form.name_), isSigned_(form.isSigned_), grade_(form.grade_), requiredGrade_(form.requiredGrade_) {

}

Form::~Form() {

}

Form &Form::operator=(const Form &form) {
    return *this;
}

std::string Form::getName() const{
    return name_;
}

bool Form::getIsSigned() const{
    return isSigned_;
}

int Form::getGrade() const{
    return grade_;
}

int Form::getRequiredGrade() const{
    return requiredGrade_;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (requiredGrade_ < bureaucrat.getGrade())
        throw GradeTooLowException();
    else
        isSigned_ = true;
}

void Form::checkGrade() {
    if (grade_ < 1 || requiredGrade_ < 1)
        throw GradeTooHighException();
    else if (grade_ > 150 || requiredGrade_ > 150)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outputStream, const Form &form) {
    std::cout << "name: " << form.getName() << ", is signed: " << form.getIsSigned() << ", grade: " 
    << form.getGrade() << ", required grade: " << form.getRequiredGrade();
    return outputStream;
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Exception: GradeTooLowException";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Exception: GradeTooHighException";
}