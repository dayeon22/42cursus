/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongmain.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:41:42 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 17:43:02 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	return 0;
}
