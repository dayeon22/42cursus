/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:39:02 by daypark           #+#    #+#             */
/*   Updated: 2022/03/24 10:35:11 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point a(0, 0);
	Point b(2, 4);
	Point c(4, 2);
	Point p1(1, 1);
	
	if (bsp(a, b, c, p1))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	return 0;
}
