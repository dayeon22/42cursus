/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:59:41 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 09:44:37 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    int n;

    std::cout << "number of zombies: ";
    std::cin >> n;
    Zombie *zombieH = zombieHorde(n, "ZombieH");

    for (int i = 0; i < n; i++){
        zombieH[i].announce();
    }
    delete[] zombieH;
}