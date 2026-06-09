/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:41:58 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/09 14:29:22 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static int	check_input(const std::string &input, std::string &value)
{
	std::cout << PINK << input << RESET << std::endl;
	if (!std::getline(std::cin, value))
		return (0);
	if (value.empty()) {
		std::cout << RED << "Field cannot be empty" << RESET << std::endl;
	}
	return (1);
}

/* 
	Checks if the format of the phone number is correct
	- must be 10 characters long
	- nust contain digits only
*/
static int	check_phone(std::string phone_number) {
	for (size_t i = 0; i < phone_number.length(); ++i) {
		if (phone_number[i] < '0' || phone_number[i] > '9')
			return (std::cerr << RED << "Unauthorized character in phone number" << RESET << std::endl, 0);
	}
	if (phone_number.length() != 10)
		return (std::cerr << RED << "Phone number must be 10 characters" << RESET << std::endl, 0);
	return (1);
}

/*
	Used when the user calls `ADD`
	Allows the user to enter the needed contact informations
*/
static int	addCommand(PhoneBook &myPhonebook) {
	std::string	first_name, last_name, nickname, darkest_secret, phone_number;
	Contact	temp;

	if (!check_input("Enter contact first name: ", first_name))
		return (0);
	if (!check_input("Enter contact last name: ", last_name))
		return (0);
	if (!check_input("Enter contact nickname: ", nickname))
		return (0);
	if (!check_input("Enter contact darkest secret: ", darkest_secret))
		return (0);
	if (!check_input("Enter phone number: ", phone_number))
		return (0);
	while (!check_phone(phone_number)) {
		if (!check_input("Enter phone number: ", phone_number))
			return (0);
	}
	temp.setFields(first_name, last_name, nickname, phone_number, darkest_secret);
	myPhonebook.addContact(temp);
	std::cout << GREEN << "Contact successfully added" << RESET << std::endl;
	return (1);
}

int main(void) {
	PhoneBook	myPhonebook;
	std::string command;
	std::string	index;

	while (1) {
		if (!check_input("What do you want to do? ", command))
			break ;
		if (command == "ADD")
		{
			if (!addCommand(myPhonebook))
				break ;
		}
		else if (command == "SEARCH") {
			std::cout << PINK << "Displaying all contacts: " << RESET << std::endl;
			myPhonebook.displayAll();
			if (!check_input("Who are you looking for?", index))
				break ;
			while (!myPhonebook.displayContact(index)) {
				if (!check_input("Who are you looking for?", index))
					break ;
			}
		}
		else if (command == "EXIT") {
			std::cout << GREEN << "Closing the phonebook..." << RESET << std::endl;
			return (0);
		}
		else
			std::cout << RED << "Unknown command, please try again" << RESET << std::endl;
	}
	std::cout << GREEN << "Closing the phonebook..." << RESET << std::endl;
	return (0);
}
