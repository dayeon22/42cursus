/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:24:20 by daypark           #+#    #+#             */
/*   Updated: 2022/05/02 12:25:00 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
   try {
        Bureaucrat bureaucrat("daypark", 1);
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        
        //Bureaucrat bureaucrat1("daypark", 0);
        
        //Bureaucrat bureaucrat2("aaa", 151);
        
        //Bureaucrat bureaucrat3("bbb", 1);
        //bureaucrat3.incrementGrade();
        
        //Bureaucrat bureaucrat4("ccc", 150);
        //bureaucrat4.decrementGrade();
   } catch (std::exception &e) {
       std::cerr << e.what() << std::endl;
   }
}