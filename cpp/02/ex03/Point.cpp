/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:48:27 by daypark           #+#    #+#             */
/*   Updated: 2022/03/24 08:32:10 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(0), y_(0) {

}

Point::Point(const float x, const float y) : x_(x), y_(y) {

}

Point::Point(const Point &point) : x_(point.x_), y_(point.y_) {

}

Point::~Point() {
	
}

Point &Point::operator=(const Point &point) {
	(void)point;
	return *this;
}

Fixed Point::getX() const {
	return this->x_;
}

Fixed Point::getY() const {
	return this->y_;
}