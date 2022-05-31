/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:26:50 by daypark           #+#    #+#             */
/*   Updated: 2022/06/01 04:01:17 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class NoOccurenceException : public std::exception {
public:
    const char *what() const throw() {
        return "Exception: NoOccurenceException";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator result = find(container.begin(), container.end(), value);
    if (result == container.end())
        throw NoOccurenceException();
    return result;
}

#endif