/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:41:58 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/03 16:35:29 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
	PhoneBook	myPhonebook;
	std::string command;

	while (1) {
		std::cout << "What do you want to do? " << std::endl;
		std::cin >> command;
		if (command == "ADD") {
			std::string	first_name, last_name, nickname, darkest_secret, phone_number;
			Contact	temp;

			std::cout << "Enter contact first name: " << std::endl;
			std::cin >> first_name;
			std::cout << "Enter contact last name: " << std::endl;
			std::cin >> last_name;
			std::cout << "Enter contact nickname: " << std::endl;
			std::cin >> nickname;
			std::cout << "Enter contact darkest secret: " << std::endl;
			std::cin >> darkest_secret;
			std::cout << "Enter phone number: " << std::endl;
			std::cin >> phone_number;
			temp.setFields(first_name, last_name, nickname, phone_number, darkest_secret);
			myPhonebook.addContact(temp);
		}
		else if (command == "SEARCH") {
			std::cout << "Loading the contact informations..." << std::endl;
			// Searching logic
		}
		else if (command == "EXIT") {
			std::cout << "Closing the phonebook..." << std::endl;
			return (0);
		}
		else {
			std::cout << "Unknown command, please try again" << std::endl;
		}
	}
	return (0);
}