/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:54:03 by daypark           #+#    #+#             */
/*   Updated: 2022/05/20 02:04:16 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Convert {
private:
	std::string str_;
public:
	Convert();
	Convert(std::string &str);
	Convert(const Convert &convert);
	~Convert();
	Convert &operator=(const Convert &convert);

	void convertToScalar();
	void convertToChar();
	void convertToInt();
	void convertToFloat();
	void convertToDouble();

	class NonDisplayableException : public std::exception {
		const char *what() const throw();
	};
	class ImpossibleException : public std::exception {
		const char *what() const throw();
	};
};

#endif
