/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 07:27:05 by daypark           #+#    #+#             */
/*   Updated: 2022/05/20 07:54:58 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

class Data {
private:
	std::string name_;
	int age_;
public:
	Data();
	Data(std::string name, int age);
	Data(const Data &data);
	~Data();
	Data &operator=(const Data &data);

	std::string getName() const;
	int getAge() const;
};
std::ostream &operator<<(std::ostream &outputStream, const Data &data);

#endif