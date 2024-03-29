/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:25:27 by daypark           #+#    #+#             */
/*   Updated: 2022/05/02 13:38:16 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150) {

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
    checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name_(bureaucrat.name_), grade_(bureaucrat.grade_) {
    
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

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Exception: GradeTooLowException";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Exception: GradeTooHighException";
}