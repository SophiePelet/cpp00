/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:50:42 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/08 17:31:00 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

# define PINK	"\033[95m"
# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"

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