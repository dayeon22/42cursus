/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:27:18 by daypark           #+#    #+#             */
/*   Updated: 2022/05/24 15:58:50 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain_;
public:
	Cat();
	Cat(const Cat &cat);
	~Cat();
	Cat &operator=(const Cat &cat);
	std::string getType() const;
	virtual void makeSound() const;
	Brain *getBrain();
};

#endif
