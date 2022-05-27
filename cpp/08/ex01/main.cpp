/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:24 by daypark           #+#    #+#             */
/*   Updated: 2022/05/27 12:17:41 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    Span s(10);

    s.addNumber(1);
    s.addNumber(5);
    s.addNumber(3);
    s.addNumber(2);
    s.addNumber(4);
/*
    Span s1 = s;
    std::cout << s1.N_ << std::endl;
    std::cout << s1.v_[0] << std::endl;
    std::cout << s1.v_[1] << std::endl;
    std::cout << s1.v_[2] << std::endl;
    std::cout << s1.v_[3] << std::endl;
    std::cout << s1.v_[4] << std::endl;

    Span s2;
    s2 = s;
    std::cout << s2.N_ << std::endl;
    std::cout << s2.v_[0] << std::endl;
    std::cout << s2.v_[1] << std::endl;
    std::cout << s2.v_[2] << std::endl;
    std::cout << s2.v_[3] << std::endl;
    std::cout << s2.v_[4] << std::endl;
*/
    s.shortestSpan();
    s.longestSpan();
    //std::cout << "shortest span: " << s.shortestSpan() << std::endl;
    //std::cout << "longest span: " << s.longestSpan() << std::endl;
}