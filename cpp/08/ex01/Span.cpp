/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:27:09 by daypark           #+#    #+#             */
/*   Updated: 2022/05/27 05:52:13 by daypark          ###   ########.fr       */
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
    v_.reserve(N_);
    std::copy(std::begin(span.v_), std::end(span.v_), v_);
}