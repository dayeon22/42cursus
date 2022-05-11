/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:35:27 by daypark           #+#    #+#             */
/*   Updated: 2022/05/11 17:02:33 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]){
	Harl harl;

	if (argc != 2){
		std::cout << "usage: ./harlFilter \"LEVEL\"" << std::endl;
		return 0;
	}
	harl.complain(argv[1]);
}
