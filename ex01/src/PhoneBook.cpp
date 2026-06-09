/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:30:53 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/09 12:27:59 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	current_nb = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
}

/*
	Adds the new contact at the correct index
	If the 8 slots are already filled, the oldest one is replaced by the new one
*/
void	PhoneBook::addContact(Contact const &newContact) {
	int	place = current_nb % 8;
	
	this->list[place] = newContact;
	this->current_nb++;
}

/* Displays all contacts in a specific format */
void	PhoneBook::displayAll() const {
	int	stored_contacts = current_nb;

	if (stored_contacts > 8)
		stored_contacts = 8;
	for (int i = 0; i < stored_contacts; ++i) {
		std::string	first_name = list[i].getFirstname();
		std::string	last_name = list[i].getLastname();
		std::string	nickname = list[i].getNickname();

		std::cout << std::right << std::setw(10) << i;
		std::cout << '|';
		if (first_name.size() > 10) {
			std::string	sub_first = first_name.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << sub_first;
			std::cout << '|';
		}
		else {
			std::cout << std::right << std::setw(10) << first_name;
			std::cout << '|';
		}
		if (last_name.size() > 10) {
			std::string	sub_last = last_name.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << sub_last;
			std::cout << '|';
		}
		else {
			std::cout << std::right << std::setw(10) << last_name;
			std::cout << '|';
		}
		if (nickname.size() > 10) {
			std::string	sub_nick = nickname.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << sub_nick << '.' << std::endl;
		}
		else
			std::cout << std::right << std::setw(10) << nickname << std::endl;
	}
	return ;
}

int	PhoneBook::displayContact(const std::string &index) const {
	int	stored_contacts = current_nb;

	if (stored_contacts > 8)
		stored_contacts = 8;
	if (index.empty())
		return (0);
	for (size_t i = 0; i < index.size(); ++i) {
		if (index[i] < '0' || index[i] > '7') {
			std::cout << RED << "Incorrect index" << RESET << std::endl;
			return (0);
		}
	}
	int	new_index = atoi(index.c_str());
	if (new_index < 0 || new_index >= stored_contacts) {
		std::cout << RED << "Contact does not exist" << RESET << std::endl;
		return (0);
	}
	std::string	first_name = list[new_index].getFirstname();
	std::string	last_name = list[new_index].getLastname();
	std::string	nickname = list[new_index].getNickname();
	std::string	darkest_secret = list[new_index].getSecret();
	std::string	phone_number = list[new_index].getPhone();
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << darkest_secret << std::endl;
	std::cout << phone_number << std::endl;
	return (1);
}