/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:29:43 by daypark           #+#    #+#             */
/*   Updated: 2022/03/28 13:54:41 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap st1("st1");

	st1.attack("st0");
	st1.takeDamage(3);
	st1.beRepaired(5);
	st1.takeDamage(20);
	st1.beRepaired(10);
	st1.guardGate();
}