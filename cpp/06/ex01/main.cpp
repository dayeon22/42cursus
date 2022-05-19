/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 07:15:34 by daypark           #+#    #+#             */
/*   Updated: 2022/05/20 08:18:15 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <cstdint>

uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data data("dayeon", 25);
	
	std::cout << data << std::endl;
	uintptr_t p = serialize(&data);
	Data *newData = deserialize(p);
	std::cout << *newData << std::endl;

	std::cout << &data << std::endl;
	p = serialize(&data);
	std::cout << deserialize(p) << std::endl;
}