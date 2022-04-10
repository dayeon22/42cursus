/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:37:01 by daypark           #+#    #+#             */
/*   Updated: 2022/04/10 17:16:57 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string ideas_[100];
public:
	Brain();
	Brain(const Brain &brain);
	~Brain();
	Brain &operator=(const Brain &brain);
	std::string getIdeas(int index);
	void setIdeas(int index, std::string ideas);
};

#endif