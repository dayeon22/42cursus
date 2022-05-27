/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:09 by daypark           #+#    #+#             */
/*   Updated: 2022/05/27 12:20:46 by daypark          ###   ########.fr       */
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
    N_ = span.N_;
    v_.resize(N_);
    std::copy(span.v_.begin(), span.v_.end(), v_.begin());

    std::cout << "@@@" << *v_.begin() << ", " << *v_.end() << std::endl;
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
    std::vector<int> temp(v_);  // 벡터라서 복사생성자 실행안되는거였음!!(여기고치기)
    std::cout << "!!!" << *temp.begin() << ", " << *temp.end() << std::endl; // 출력이상함!!
    sort(temp.begin(), temp.end());
    std::vector<int>::iterator it;
    int min = 0;

    for (it = temp.begin(); it != temp.end(); it++) {
        std::cout << *it << std::endl;
    }
    return min;
}

int Span::longestSpan() {
    if (N_ < 2)
        throw NoNumberException();
    int min = *max_element(v_.begin(), v_.end());
    int max = *min_element(v_.begin(), v_.end());
    return max - min;
}

const char *Span::NoSpaceException::what() const throw() {
    return "Exception: NoSpaceException";
}

const char *Span::NoNumberException::what() const throw() {
    return "Exception: NoNumberException";
}