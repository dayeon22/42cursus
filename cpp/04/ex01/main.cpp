/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:09:17 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 22:14:14 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main() {
	Animal *animal[10];
	int i;

	for (i = 0; i < 10; i++) {
		if (i < 5) {
			animal[i] = new Dog();
		}
		else {
			animal[i] = new Cat();
		}
	}

	for (i = 0; i < 10; i++) {
		delete animal[i];
	}
}
