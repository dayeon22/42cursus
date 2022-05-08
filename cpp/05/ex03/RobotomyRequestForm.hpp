/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:06:07 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 15:36:52 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &rr);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rr);

	void execute(Bureaucrat const &executor) const;
	
	class RobotomizeFailedException : public std::exception {
		const char *what() const throw();
	};
};

#endif