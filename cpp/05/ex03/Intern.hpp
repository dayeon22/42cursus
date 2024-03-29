/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:31:00 by daypark           #+#    #+#             */
/*   Updated: 2022/05/17 07:57:50 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &intern);
	~Intern();
	Intern &operator=(const Intern &intern);

	Form *makeForm(std::string name, std::string target);
	Form *makeSCForm(std::string target);
	Form *makeRRForm(std::string target);
	Form *makePPForm(std::string tatget);

	class WrongFormName : public std::exception {
		const char *what() const throw();
	};
};

#endif