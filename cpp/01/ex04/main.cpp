/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:17:39 by daypark           #+#    #+#             */
/*   Updated: 2022/02/17 17:21:54 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int printErr(std::string errMsg){
	std::cerr << errMsg << std::endl;
	return 0;
}

int main(int argc, char *argv[]){
	if (argc != 4){
		return (printErr("usage: ./sed file_name str_to_be_replaced str_to_replace"));
	}
	std::ifstream fin(argv[1]);
	if (fin.fail()){
		return (printErr("failed to read file"));
	}
	std::string replaceFile = argv[1];
	replaceFile += ".replace";
	std::ofstream fout(replaceFile);
	if (fout.fail()){
		fin.close();
		return (printErr("failed to make .replace file"));
	}

	std::string line;
	while (true){
		std::getline(fin, line);

		size_t start = 0;
		size_t index = 0;
		while (true){
			index = line.find(argv[2], start);
			if (index == std::string::npos){
				fout << line.substr(start);
				break;
			}
			fout << line.substr(start, index - start);
			fout << argv[3];
			start = index + std::strlen(argv[2]);
		}
		if (fin.eof())
			break;
		fout << std::endl;
	}
	fin.close();
	fout.close();
}
