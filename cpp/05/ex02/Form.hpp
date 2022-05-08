/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:31:32 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 02:02:34 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
    const std::string target_; // 추가해줬음(생성자 등 바꿀거 바꾸기)
    const std::string type_;
    bool isSigned_;
    const int signGrade_;
    const int executeGrade_;
public:
    Form();
    Form(std::string target, std::string type, int signGrade, int executeGrade);
    Form(const Form &form);
    virtual ~Form();
    Form &operator=(const Form &form);
    
    std::string getTarget() const;
    std::string getType() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat &bureaucrat);
    void checkGrade();
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };
    class CannotExecuteException : public std::exception {
        const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &outputStream, const Form &form);

#endif