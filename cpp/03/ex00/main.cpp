/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:29:43 by daypark           #+#    #+#             */
/*   Updated: 2022/03/28 10:03:21 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap ct1("ct1");
	ClapTrap ct2(ct1);
	ClapTrap ct3;

	ct1.attack("ct0");
	ct1.takeDamage(3);
	ct1.beRepaired(5);
	ct1.takeDamage(20);
	ct1.beRepaired(10);
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
	ct3.attack("ct0");
}