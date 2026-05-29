/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:48:12 by sopelet           #+#    #+#             */
/*   Updated: 2026/05/29 19:06:56 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < ac ; ++i) {
		std::string str(av[i]);
		for (size_t j = 0; j < str.size(); ++j) {
			std::cout << static_cast<char>(std::toupper(str[j]));
		}
	}
	std::cout << '\n';
	return (0);
}
