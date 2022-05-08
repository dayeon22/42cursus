/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 14:03:16 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("daypark", 42);
        std::cout << bureaucrat << std::endl;

        ShrubberyCreationForm scf("home");  // 145, 137
        scf.beSigned(bureaucrat);
        scf.execute(bureaucrat);

        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}