/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:33:34 by daypark           #+#    #+#             */
/*   Updated: 2022/05/24 15:29:06 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

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