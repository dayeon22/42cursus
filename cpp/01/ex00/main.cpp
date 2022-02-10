/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:59:41 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 08:41:28 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie zombie1("zombie1");
    zombie1.announce();

    Zombie *zombie2 = new Zombie("zombie2");
    zombie2->announce();
    delete zombie2;

    Zombie *zombie3 = newZombie("zombie3");
    zombie3->announce();
    delete zombie3;

    randomChump("zombie4");
}