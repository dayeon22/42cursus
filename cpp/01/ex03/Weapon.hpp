/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:15:03 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 15:26:00 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type_;
public:
	Weapon(std::string type);
	std::string getType(); // returns a const reference to this string해야함! 근데뭔뜻?
	void setType(std::string type);
};

#endif
