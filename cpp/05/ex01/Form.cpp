/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:54:14 by daypark           #+#    #+#             */
/*   Updated: 2022/05/03 09:01:18 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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

Form &operator=(const Form form) {
    isSigned_ = form.isSigned_;
    grade_ = form.grade_;
    requiredGrade_ = form.requiredGrade_;
    return *this;
}

std::string Form::getName() {
    return name_;
}

bool Form::getIsSigned() {
    return isSigned_;
}

int Form::getGrade() {
    return grade_;
}

int Form::getRequiredGrade() {
    return requiredGrade_;
}

void Form::beSigned(Bureaucrat bureaucrat) {
    if (requiredGrade_ > bureaucrat.getGrade())
        throw GradeTooLowException();
    else
        bureaucrat.signForm();
        //isSigned_ = true;
}

void Form::checkGrade() {
    if (grade_ < 1)
        throw GradeTooHighException();
    else if (grade_ > 150)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::otream &outputStream, const Form &form) {
    std::cout << form.getName() << ", " << form.getIsSigned() << ", " 
    << form.getGrade() << ", " << form.getRequiredGrade() << std::endl;
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Exception: GradeTooLowException";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Exception: GradeTooHighException";
}