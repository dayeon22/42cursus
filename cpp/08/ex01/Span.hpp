/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:15 by daypark           #+#    #+#             */
/*   Updated: 2022/05/27 12:03:54 by daypark          ###   ########.fr       */
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
public:
    unsigned int N_;
    std::vector<int> v_;
    Span();
    Span(unsigned int N);
    Span(const Span &span);
    ~Span();
    Span &operator=(const Span &span);

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();

    class NoSpaceException : public std::exception {
        const char *what() const throw();
    };

    class NoNumberException : public std::exception {
        const char *what() const throw();
    };
};

#endif