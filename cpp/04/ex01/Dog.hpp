/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:26:53 by daypark           #+#    #+#             */
/*   Updated: 2022/04/10 17:18:32 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain_;
public:
	Dog();
	Dog(const Dog &dog);
	~Dog();
	Dog &operator=(const Dog &dog);
	virtual std::string getType() const;
	virtual void makeSound() const;
	Brain *getBrain();
};

#endif