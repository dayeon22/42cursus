/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:15 by daypark           #+#    #+#             */
/*   Updated: 2022/05/27 05:52:15 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int N_;
    std::vector<int> v_;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &span);
    ~Span();
    Span &operator=(const Span &span);

    void addNumber(int num); //숫자를 넣고 만약 N개를 넘는다면 exception
    int shortestSpan(); // 1개나 0개라면 exception
    int longestSpan(); // 1개나 0개라면 exception
};

#endif`