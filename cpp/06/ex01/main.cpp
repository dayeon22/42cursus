/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 07:15:34 by daypark           #+#    #+#             */
/*   Updated: 2022/05/29 22:05:50 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>

typedef struct s_Data {
	int num;
	std::string str;
} Data;

uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data data;
	data.num = 42;
	data.str = "Hello World!";
	
	std::cout << &data << std::endl;
	uintptr_t p = serialize(&data);
	Data *newData = deserialize(p);
	std::cout << newData << std::endl;

	std::cout << "num: " << newData->num << std::endl;
	std::cout << "str: " << newData->str << std::endl;
}