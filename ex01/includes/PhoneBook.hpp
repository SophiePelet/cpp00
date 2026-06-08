/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:50:42 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/08 17:14:47 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(Contact const &newContact);
	void	displayAll() const;
	int		displayContact(const std::string &index) const;
private:
	Contact list[8];
	int		current_nb;
};

#endif