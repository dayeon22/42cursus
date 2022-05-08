/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:06:04 by daypark           #+#    #+#             */
/*   Updated: 2022/05/08 15:42:44 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, "SC", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &sc) : 
Form(sc.getTarget(), sc.getType(), sc.getSignGrade(), sc.getExecuteGrade()) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &sc) {
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	
	std::ofstream ofs;
	std::string asciiTree =
	"                                                      .\n"
    "                                          .         ;  \n"
    "             .              .              ;%     ;;   \n"
    "               ,           ,                :;%  %;   \n"
    "                :         ;                   :;%;'     .,   \n"
    "       ,.        %;     %;            ;        %;'    ,;\n"
    "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
    "          %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
    "           ;%;      %;        ;%;        % ;%;  ,%;'\n"
    "            `%;.     ;%;     %;'         `;%%;.%;'\n"
    "             `:;%.    ;%%. %@;        %; ;@%;%'\n"
    "                `:%;.  :;bd%;          %;@%;'\n"
    "                  `@%:.  :;%.         ;@@%;'   \n"
    "                    `@%.  `;@%.      ;@@%;         \n"
    "                      `@%%. `@%%    ;@@%;        \n"
    "                        ;@%. :@%%  %@@%;       \n"
    "                          %@bd%%%bd%%:;     \n"
    "                            #@%%%%%:;;\n"
    "                            %@@%%%::;\n"
    "                            %@@@%(o);  . '         \n"
    "                            %@@@o%;:(.,'         \n"
    "                        `.. %@@@o%::;         \n"
    "                           `)@@@o%::;         \n"
    "                            %@@(o)::;        \n"
    "                           .%@@@@%::;         \n"
    "                           ;%@@@@%::;.          \n"
    "                          ;%@@@@%%:;;;. \n"
    "                      ...;%@@@@@%%:;;;;,..    \n";

	ofs.open(getTarget() + "_shrubbery");
	if (ofs.fail()) {
		throw CannotOpenFileException();
	}
	ofs << asciiTree;
	ofs.close();
}

const char *ShrubberyCreationForm::CannotOpenFileException::what() const throw() {
    return "Exception: CannotExecuteFileException";
}