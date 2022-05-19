/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayeon <daypark@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:44:13 by dayeon            #+#    #+#             */
/*   Updated: 2022/05/17 17:13:25 by dayeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>

class Convert {
private:
	std::string str_;
public:
	Convert();
	Convert(std::string &str);
	Convert(const Convert &convert);
	~Convert();
	Convert &operator=(const Convert &convert);

	void convertTo();
	void convertToChar();
	void convertToInt();
	void convertToFloat();
	void convertToDouble();
};

#endif
