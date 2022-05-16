/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/17 08:09:41 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("bureaucrat", 1);
        Intern intern;

        Form *f1 = intern.makeForm("shrubbery creation", "sc");
        bureaucrat.signForm(*f1);
        bureaucrat.executeForm(*f1);
        
        Form *f2 = intern.makeForm("robotomy request", "rr");
        bureaucrat.signForm(*f2);
        bureaucrat.executeForm(*f2);

        Form *f3 = intern.makeForm("presidential pardon", "pp");
        bureaucrat.signForm(*f3);
        bureaucrat.executeForm(*f3);

        Form *f4 = intern.makeForm("formform", "aaaa");

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}