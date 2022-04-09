/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:52:06 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 22:03:16 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas_[i] = "ideas";
	}
}

Brain::Brain(const Brain &brain) {
	*this = brain;
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
	std::cout << "12222222" << std::endl;
	Brain *newBrain = new Brain();

	for (int i = 0; i < 100; i++) {
		newBrain->ideas_[i] = brain.ideas_[i];
	}
	return *newBrain;
}