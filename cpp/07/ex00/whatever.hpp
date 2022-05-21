/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:18:33 by daypark           #+#    #+#             */
/*   Updated: 2022/05/21 18:39:04 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b) {
    T temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b) {
    if (a < b)
        return a;
    return b;
}

template <typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    return b;
}