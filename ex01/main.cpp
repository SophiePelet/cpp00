/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:41:58 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/08 16:52:17 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

/* 
	Checks if the format of the phone number is correct
	- must be 10 characters long
	- nust contain digits only
*/
int	check_phone(std::string phone_number) {
	for (size_t i = 0; i < phone_number.length(); ++i) {
		if (phone_number[i] < '0' || phone_number[i] > '9')
			return (std::cerr << "Unauthorized character in phone number" << std::endl, 0);
	if (phone_number.length() != 10)
		return (std::cerr << "Phone number must be 10 characters" << std::endl, 0);
	}
	return (1);
}

/*
	Used when the user calls `ADD`
	Allows the user to enter the needed contact informations
*/
void	addCommand(PhoneBook &myPhonebook) {
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
	while (!check_phone(phone_number)) {
		std::cout << "Enter phone number: " << std::endl;
		std::cin >> phone_number;
	}
	temp.setFields(first_name, last_name, nickname, phone_number, darkest_secret);
	myPhonebook.addContact(temp);
	std::cout << "Contact successfully added" << std::endl;
}

int main(void) {
	PhoneBook	myPhonebook;
	std::string command;
	std::string	index;

	while (1) {
		std::cout << "What do you want to do? " << std::endl;
		std::cin >> command;
		if (command == "ADD")
			addCommand(myPhonebook);
		else if (command == "SEARCH") {
			std::cout << "Displaying all contacts" << std::endl;
			myPhonebook.displayAll();
			std::cout << "Who are you looking for?" << std::endl;
			std::cin >> index;
			while (!myPhonebook.displayContact(index)) {
				std::cout << "Incorrect index" << std::endl;
				std::cout << "Who are you looking for?" << std::endl;
				std::cin >> index;
			}
		}
		else if (command == "EXIT") {
			std::cout << "Closing the phonebook..." << std::endl;
			return (0);
		}
		else
			std::cout << "Unknown command, please try again" << std::endl;
	}
	return (0);
}
