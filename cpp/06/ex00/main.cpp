/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayeon <daypark@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:35:40 by dayeon            #+#    #+#             */
/*   Updated: 2022/05/17 17:19:37 by dayeon           ###   ########.fr       */
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
	convert.convertTo();
}
