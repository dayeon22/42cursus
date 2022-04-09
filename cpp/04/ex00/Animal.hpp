/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:10:15 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 17:24:30 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type_;
public:
	Animal();
	Animal(const Animal &animal);
	~Animal();
	Animal &operator=(const Animal &animal);
	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif