/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:17:39 by daypark           #+#    #+#             */
/*   Updated: 2022/02/16 11:17:41 by daypark          ###   ########.fr       */
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
		return 0;
	}
	std::string replaceFile = argv[1];
	replaceFile += ".replace";
	std::ofstream fout(replaceFile);
	if (fout.fail()){
		std::cerr << "failed to make .replace file" << std::endl;
		fin.close();
		return 0;
	}

	std::string line;
	size_t index;
	while (true){
		std::getline(fin, line);

		while (true){
			index = line.find(argv[2]);
			if (index == std::string::npos){
				fout << line.substr(0, std::string::npos);
				break;
			}
			fout << line.substr(0, index);
			fout << argv[3];
			line = line.substr(index + std::strlen(argv[2]));
		}
		if (fin.eof())
			break;
		fout << std::endl;
	}
	fin.close();
	fout.close();
}
