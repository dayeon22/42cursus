/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/29 17:39:21 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bureaucrat("daypark", 42);
    std::cout << bureaucrat << std::endl;

    try {
        Form form1("form1", 0, 1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form form2("form2", 1, 151);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    Form form3("form3", 1, 1);
    bureaucrat.signForm(form3);

    Form form4("form4", 44, 1);
    std::cout << form4 << std::endl;
    bureaucrat.signForm(form4);
}