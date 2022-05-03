/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/03 15:06:10 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("daypark", 42);
        std::cout << bureaucrat << std::endl;

        //Form form1("form1", 0, 1);

        //Form form2("form2", 1, 151);

        // Form form3("form3", 1, 1);
        // bureaucrat.signForm(form3);

        // Form form4("form4", 1, 44);
        // std::cout << form4 << std::endl;
        // bureaucrat.signForm(form4);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}