/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:12:37 by daypark           #+#    #+#             */
/*   Updated: 2022/05/24 10:47:24 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> arr(10);
    Array<int> arr1 = arr;
    
    std::cout << arr << std::endl;
    arr[1] = 1;
    std::cout << arr[1] << std::endl;
    std::cout << arr1[1] << std::endl;

    Array<std::string> arr2(3);
    arr2[0] = "000";
    arr2[1] = "111";
    arr2[2] = "222";
    std::cout << arr2 << std::endl;

    try {
        arr2[3] = "333";
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}