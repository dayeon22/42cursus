/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:42:48 by daypark           #+#    #+#             */
/*   Updated: 2022/05/21 19:25:03 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    int iarr[5] = {1, 2, 3, 4, 5};
    double darr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char carr[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::string sarr[3] = {"hello", "world", "!!!"};

    iter(iarr, 5, &printElement);
    std::cout << std::endl;
    iter(darr, 5, &printElement);
    std::cout << std::endl;
    iter(carr, 7, &printElement);
    std::cout << std::endl;
    iter(sarr, 3, &printElement);
    std::cout << std::endl;
}