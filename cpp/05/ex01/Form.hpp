/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:31:32 by daypark           #+#    #+#             */
/*   Updated: 2022/05/29 17:45:05 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
private:
    const std::string name_;
    bool isSigned_;
    const int signGrade_;
    const int executeGrade_;
public:
    Form();
    Form(std::string name, int signGrade, int executeGrade);
    Form(const Form &form);
    ~Form();
    Form &operator=(const Form &form);
    
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat &bureaucrat);
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