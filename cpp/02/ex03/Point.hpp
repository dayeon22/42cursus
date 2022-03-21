/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:34:34 by daypark           #+#    #+#             */
/*   Updated: 2022/03/21 17:26:12 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const x_;
	Fixed const y_;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &point);
	~Point();
	Point &operator=(const Point &point);
};

#endif