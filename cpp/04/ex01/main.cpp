/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:09:17 by daypark           #+#    #+#             */
/*   Updated: 2022/05/26 15:38:36 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	std::cout << "========== DEEP COPY TEST ==========" << std::endl;
	
	Cat c1;
	Cat c2(c1);
	Cat c3;
	c3 = c1;

	c1.getBrain()->setIdeas(0, "@@@@@");
	std::cout << "cat - " << c1.getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat - " << c2.getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat - " << c3.getBrain()->getIdeas(0) << std::endl;

	Dog d1;
	Dog d2(d1);
	Dog d3;
	d3 = d1;

	d1.getBrain()->setIdeas(0, "#####");
	std::cout << "dog - " << d1.getBrain()->getIdeas(0) << std::endl;
	std::cout << "dog - " << d2.getBrain()->getIdeas(0) << std::endl;
	std::cout << "dog - " << d3.getBrain()->getIdeas(0) << std::endl;

	std::cout << "====================================" << std::endl;
}