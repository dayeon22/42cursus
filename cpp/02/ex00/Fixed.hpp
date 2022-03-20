/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:57:34 by daypark           #+#    #+#             */
/*   Updated: 2022/03/20 12:04:21 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int value_;
	const static int bits_ = 8;
public:
	Fixed();
	Fixed (const Fixed &fixed);
	~Fixed();
	Fixed & operator = (const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
