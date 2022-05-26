/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:12:37 by daypark           #+#    #+#             */
/*   Updated: 2022/05/26 16:46:42 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    
    delete [] mirror;//


    std::cout << "========== My test ==========" << std::endl;
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


    return 0;
}