/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/28 20:25:19 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bureaucrat("daypark", 1);
    bureaucrat.decrementGrade();
    std::cout << bureaucrat << std::endl;

    try {    
        Bureaucrat bureaucrat1("daypark", 0);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat2("aaa", 151);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat3("bbb", 1);
        bureaucrat3.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat4("ccc", 150);
        bureaucrat4.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}