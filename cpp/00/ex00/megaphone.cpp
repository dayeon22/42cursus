/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:49:33 by daypark           #+#    #+#             */
/*   Updated: 2021/12/23 11:49:37 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	capitalizeString(std::string s)
{
	std::string	res;
	int			i;

	for (i = 0; i < (int)s.size(); i++)
	{
		res += toupper(s[i]);
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		std::cout << capitalizeString(argv[i]);
	}
	return (0);
}
