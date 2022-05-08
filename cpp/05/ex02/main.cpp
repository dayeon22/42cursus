/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 16:57:04 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("daypark", 70);
        std::cout << bureaucrat << std::endl;

        ShrubberyCreationForm sc("home");  // 145, 137
        sc.beSigned(bureaucrat);
        sc.execute(bureaucrat);

        RobotomyRequestForm rr("robo");  // 72, 45
        rr.beSigned(bureaucrat);
        rr.execute(bureaucrat);
        
        PresidentialPardonForm pp("presidnet"); // 25, 5
        pp.beSigned(bureaucrat);
        pp.execute(bureaucrat);

        Bureaucrat b1("b1", 40);
        RobotomyRequestForm rr1("robo");
        b1.signForm(rr1);
        b1.executeForm(rr1);
        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}