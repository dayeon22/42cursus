/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:42:49 by daypark           #+#    #+#             */
/*   Updated: 2022/05/21 19:30:08 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void iter(T *addr, unsigned int len, void (*fn)(T t)) {
    for (int i = 0; i < len; i++) {
        fn(addr[i]);
    }
}

template <typename T>
void printElement(T t) {
    std::cout << t << " ";
}