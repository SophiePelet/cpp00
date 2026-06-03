/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:30:53 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/03 16:30:38 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	current_nb = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::addContact(Contact const &newContact) {
	int	place = current_nb % 8;
	
	this->list[place] = newContact;
	this->current_nb++;
}