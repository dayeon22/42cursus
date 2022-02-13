/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:17:39 by daypark           #+#    #+#             */
/*   Updated: 2022/02/13 18:55:07 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
	if (argc != 4){
		std::cerr << "usage: ./sed file_name str_to_be_replaced str_to_replace" << std::endl;
		return 0;
	}
	std::ifstream fin(argv[1]);
	if (fin.fail()){
		std::cerr << "failed to read file" << std::endl;
	}
	fin.close();
}