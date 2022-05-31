/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:42:49 by daypark           #+#    #+#             */
/*   Updated: 2022/06/01 00:04:56 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter(const T *addr, unsigned int len, void (*fn)(const T &t)) {
    for (int i = 0; i < len; i++) {
        fn(addr[i]);
    }
}

template <typename T>
void printElement(T t) {
    std::cout << t << " ";
}