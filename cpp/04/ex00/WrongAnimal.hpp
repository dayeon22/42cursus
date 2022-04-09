/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:33:34 by daypark           #+#    #+#             */
/*   Updated: 2022/04/09 17:36:15 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type_;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &wrongAnimal);
	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
	std::string getType() const;
	void makeSound() const;
};

#endif