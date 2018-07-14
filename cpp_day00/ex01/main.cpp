// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/02 10:19:50 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/02 10:19:51 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Phonebook.class.hpp"

void printLine(void) {
    std::cout << std::string(5, ' ') << "index" << '|';
    std::cout << "first name|" << " last name|" << "  nickname" << std::endl;
}

int main(void)
{
	int i = 0;
	int index = 1;
	std::string buf;
	Phonebook phonebook = Phonebook();
	Contact contact;
	Contact *contactp;

	while (1) {
		std::cout << "Please enter ADD, EXIT or SEARCH" << std::endl;
		if (!(std::cin >> buf))
			break ;
		if (buf == "exit" || buf == "EXIT")
			break ;
		else if (buf == "add" || buf == "ADD")
		{
			if (phonebook.Full())
				std::cout << "Phonebook is full sorry. Restart the program" << std::endl;
			else
			{
				std::cout << "Enter your first name" << std::endl;
				std::cin >> buf;
				contact.setFirstName(buf);

				std::cout << "Enter your last name" << std::endl;
				std::cin >> buf;
				contact.setLastName(buf);

				std::cout << "Enter your nickname" << std::endl;
				std::cin >> buf;
				contact.setNickname(buf);

				std::cout << "Enter your login" << std::endl;
				std::cin >> buf;
				contact.setLogin(buf);

				std::cout << "Enter your postal adress" << std::endl;
				std::cin >> buf;
				contact.setPostalAddress(buf);

				std::cout << "Enter your email adress" << std::endl;
				std::cin >> buf;
				contact.setEmailAddress(buf);

				std::cout << "Enter your phone number" << std::endl;
				std::cin >> buf;
				contact.setPhoneNumber(buf);

				std::cout << "Enter your birthday date" << std::endl;
				std::cin >> buf;
				contact.setBirthdayDate(buf);

				std::cout << "Enter your favorite meal" << std::endl;
				std::cin >> buf;
				contact.setFavoriteMeal(buf);

				std::cout << "Enter your underwear color" << std::endl;
				std::cin >> buf;
				contact.setUnderwearColor(buf);

				std::cout << "Enter your darkest secret" << std::endl;
				std::cin >> buf;
				contact.setDarkestSecret(buf);

				contact.index = index;
				phonebook.AddContact(&contact);
				index++;
			}
		}
		else if (buf == "search" || buf == "SEARCH")
		{
			printLine();
			phonebook.PrintLinesContacts();
			std::cout << "Enter index to get more information or something else to break" << std::endl;
			std::cin >> buf;
			phonebook.PrintOneContact(atoi(buf.c_str()));
		}
		else
			std::cout << "Sorry i don't understand you" << std::endl;
	}
	std::cout << "Closing phonebook" << std::endl;
	return (0);
}