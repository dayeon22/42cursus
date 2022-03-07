/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:35:27 by daypark           #+#    #+#             */
/*   Updated: 2022/03/07 16:02:35 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char *argv[]){
	Karen karen;

	if (argc != 2){
		std::cout << "usage: ./karenFilter \"LEVEL\"" << std::endl;
		return 0;
	}
	karen.complain(argv[1]);
}
