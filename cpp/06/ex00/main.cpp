/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:53:50 by daypark           #+#    #+#             */
/*   Updated: 2022/05/20 01:31:23 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "./convert string_to_convert" << std::endl;
		return 0;
	}
	std::string input = argv[1];
	Convert convert(input);
	convert.convertToScalar();
}
