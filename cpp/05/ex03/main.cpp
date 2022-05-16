/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/17 07:31:54 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat b1("b1", 1);
        ShrubberyCreationForm sc("sc");  // 145, 137
        b1.signForm(sc);
        b1.executeForm(sc);

        Bureaucrat b2("b2", 1);
        RobotomyRequestForm rr("robo");  // 72, 45
        b2.signForm(rr);
        b2.executeForm(rr);
        
        Bureaucrat b3("b3", 1);
        PresidentialPardonForm pp("president");  // 25, 5
        b3.signForm(pp);
        b3.executeForm(pp);

        Intern intern;
        Form *f = intern.makeForm("shrubbery creation", "asdf");
        f->getName();

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}