/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:42 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 15:28:24 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
private:
	std::string humanName_;
	Weapon &weapon_;
public:
	HumanA(std::string hunamName, Weapon &weapon);
	void attack();
};

#endif
