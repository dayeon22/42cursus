/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/29 18:13:09 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 50);
    Bureaucrat b3("b3", 100);

    ShrubberyCreationForm sc("sc");  // 145, 137
    b1.signForm(sc);
    b1.executeForm(sc);

    RobotomyRequestForm rr("robo");  // 72, 45
    b2.signForm(rr);
    b2.executeForm(rr);
    b1.executeForm(rr);
    
    PresidentialPardonForm pp("president");  // 25, 5
    b3.signForm(pp);
    b3.executeForm(pp);
    b1.signForm(pp);
    b1.executeForm(pp);
}