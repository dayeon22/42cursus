/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:29:43 by daypark           #+#    #+#             */
/*   Updated: 2022/03/28 15:32:54 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap ft1("ft1");

	ft1.attack("ft0");
	ft1.takeDamage(3);
	ft1.beRepaired(5);
	ft1.takeDamage(20);
	ft1.beRepaired(10);
	ft1.highFivesGuys();
}