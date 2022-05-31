/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:24 by daypark           #+#    #+#             */
/*   Updated: 2022/06/01 04:37:16 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    Span sp = Span(5);
    Span sp1(10000);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;

    std::list<int> v;
    for (int i = -5000; i < 5000; i++) {
        v.push_back(i);
    }
    sp1.addNumberItr(v.begin(), v.end());
    std::cout << "shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp1.longestSpan() << std::endl;
}