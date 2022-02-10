/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:58:09 by daypark           #+#    #+#             */
/*   Updated: 2022/02/10 08:40:54 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name_;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif