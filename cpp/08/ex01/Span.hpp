/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:15 by daypark           #+#    #+#             */
/*   Updated: 2022/06/01 04:37:29 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
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

    int shortestSpan();
    int longestSpan();
    void addNumber(int num);
    template <typename T>
    void addNumberItr(T start, T end) {
        if (std::distance(start, end) + v_.size() > N_)
            return ;
        while (start != end)
            v_.push_back(*start++);
    }

    class NoSpaceException : public std::exception {
        const char *what() const throw();
    };

    class NoNumberException : public std::exception {
        const char *what() const throw();
    };
};

#endif