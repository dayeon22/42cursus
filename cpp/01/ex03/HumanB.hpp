/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:44:42 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 15:18:48 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB{
private:
	std::string humanName_;
	std::string weaponType_;
public:
	HumanB(std::string humanName);
	void setWeapon(Weapon &weapon);
	void attack();
};

#endif
