/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:33:17 by daypark           #+#    #+#             */
/*   Updated: 2022/05/21 17:12:47 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base *generate(void) {
    Base *base;
    int num;

    srand((unsigned int)time(NULL));
    num = rand() % 3;

    if (num == 0)
        base = dynamic_cast<Base*>(new A());
    else if (num == 2)
        base = dynamic_cast<Base*>(new B());
    else
        base = dynamic_cast<Base*>(new C());

    return base;
}

void identify(Base *p) {
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);
    
    if (a != NULL)
        std::cout << "A" << std::endl;
    else if (b != NULL)
        std::cout << "B" << std::endl;
    else if (c != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base &p) {
    int arr[3] = {0};
    char carr[3] = {'A', 'B', 'C'};
    
    try {
        A &a = dynamic_cast<A&>(p);
    } catch (std::exception &e) {
        arr[0] = 1;
    }
    try {
        B &b = dynamic_cast<B&>(p);
    } catch (std::exception &e) {
        arr[1] = 1;
    }
    try {
        C &c = dynamic_cast<C&>(p);
    } catch(std::exception &e) {
        arr[2] = 1;
    }

    for (int i = 0; i < 3; i++) {
        if (arr[i] == 0)
            std::cout << carr[i] << std::endl;
    }
}

int main() {
    Base *base = generate();

    identify(base);
    identify(*base);
}