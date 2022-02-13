/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:42 by daypark           #+#    #+#             */
/*   Updated: 2022/02/13 12:24:43 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
private:
	std::string name_;
	Weapon &weapon_;
public:
	HumanA(std::string name, Weapon &weapon);
	void attack();
};

#endif
