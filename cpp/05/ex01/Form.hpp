/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:31:32 by daypark           #+#    #+#             */
/*   Updated: 2022/05/02 18:39:42 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
    const std::string name_;
    bool isSigned_;
    int grade_;
    int requiredGrade_;
public:
    Form();
    Form(std::string name, int grade, int requiredGrade);
    Form(const Form &form);
    ~Form();
    Form &operator=(const Form &form);
    
    std::string getName();
    bool getIsSigned();
    int getGrade();
    int getRequiredGrade();
    void beSigned(Bureaucrat bureaucrat);
    void checkGrade();
    
    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &outputStream, const Form &form);

#endif