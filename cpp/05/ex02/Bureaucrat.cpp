/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:25:27 by daypark           #+#    #+#             */
/*   Updated: 2022/05/17 08:06:59 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150) {

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
    checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name_(bureaucrat.getName()), grade_(bureaucrat.getGrade()) {
    
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    this->grade_ = bureaucrat.grade_;
    return *this;
}

std::string Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    grade_ -= 1;
    checkGrade();
}

void Bureaucrat::decrementGrade() {
    grade_ += 1;
    checkGrade();
}

void Bureaucrat::checkGrade() {
    if (grade_ < 1)
        throw GradeTooHighException();
    else if (grade_ > 150)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outputStream, const Bureaucrat &bureaucrat) {
    std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return outputStream;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << name_ << " signed " << form.getTarget() << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << name_ << " couldn't sign " << form.getTarget() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(Form const &form) {
    try {
        form.execute(*this);
        std::cout << name_ << " executed " << form.getTarget() << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << name_ << " couldn't execute " << form.getTarget() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Exception: GradeTooLowException";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Exception: GradeTooHighException";
}