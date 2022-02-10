/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:03:13 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 09:50:16 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
    Zombie *zombieH = new Zombie[N];

    for (int i = 0; i < N; i++){
        zombieH[i].setName(name + std::to_string(i));
    }
    return zombieH;
}