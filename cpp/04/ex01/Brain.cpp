/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:52:06 by daypark           #+#    #+#             */
/*   Updated: 2022/05/26 15:10:10 by daypark          ###   ########.fr       */
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
	std::cout << "[Brain] Copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
	for (int i = 0; i < 100; i++) {
		this->ideas_[i] = brain.ideas_[i];
	}
	return *this;
}

std::string Brain::getIdeas(int index) {
	return ideas_[index];
}

void Brain::setIdeas(int index, std::string idea) {
	ideas_[index] = idea;
}