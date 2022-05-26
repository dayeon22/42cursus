/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:26:50 by daypark           #+#    #+#             */
/*   Updated: 2022/05/27 02:57:26 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

class NoOccurenceException : public std::exception {
public:
    const char *what() const throw() {
        return "Exception: NoOccurenceException";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator result = find(std::begin(container), std::end(container), value);
    if (result == std::end(container))
        throw NoOccurenceException();
    return result;
}

#endif