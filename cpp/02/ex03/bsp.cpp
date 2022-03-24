/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:59:06 by daypark           #+#    #+#             */
/*   Updated: 2022/03/24 10:14:12 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int countContact(Point const p1, Point const p2, Point const p3, Point const point) {
	Fixed s0;
	Fixed s1;
	Fixed s2;
	Fixed posx;

	if ((p1.getY() > point.getY()) != (p2.getY() > point.getY()))
	{
		s0 = p2.getX() - p1.getX();
		s1 = p2.getY() - p1.getY();
		s2 = point.getY() - p1.getY();
		posx = s0 * s2 / s1 + p1.getX();
		if (posx < point.getX())
			return 1;
	}
	return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	int cnt = 0;

	cnt += countContact(a, b, c, point);
	cnt += countContact(b, c, a, point);
	cnt += countContact(c, a, b, point);

	return (cnt % 2 == 1);
}