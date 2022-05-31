/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:09 by daypark           #+#    #+#             */
/*   Updated: 2022/06/01 02:48:41 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
    N_ = 0;
    v_.reserve(N_);
}

Span::Span(unsigned int N) {
    N_= N;
    v_.reserve(N_);
}

Span::Span(const Span &span) {
    *this = span;
}

Span::~Span() {

}

Span &Span::operator=(const Span &span) {
    if (this != &span) {
        N_ = span.N_;
        v_.resize(N_);
        std::copy(span.v_.begin(), span.v_.end(), v_.begin());
    }
    return *this;
}

void Span::addNumber(int num) {
    if (N_ == v_.size())
        throw NoSpaceException();
    v_.push_back(num);
}

int Span::shortestSpan() {
    if (N_ < 2)
        throw NoNumberException();
    
    std::vector<int> temp(v_);
    sort(temp.begin(), temp.end());
    std::vector<int>::iterator it = temp.begin();
    int min = std::abs(*(it + 1) - *it);
    int diff = 0;
    for (; it != temp.end() - 1; it++) {
        diff = std::abs(*(it + 1) - *it);
        if (min > diff)
            min = diff;
    }
    return min;
}

int Span::longestSpan() {
    if (N_ < 2)
        throw NoNumberException();
    int min = *min_element(v_.begin(), v_.end());
    int max = *max_element(v_.begin(), v_.end());
    return max - min;
}

const char *Span::NoSpaceException::what() const throw() {
    return "Exception: NoSpaceException";
}

const char *Span::NoNumberException::what() const throw() {
    return "Exception: NoNumberException";
}