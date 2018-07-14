// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/02 10:19:28 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/02 10:19:31 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Contact.class.hpp"

/*
*** Default constructor
*/

Contact::Contact(void) {
    index = -1;
    return ;
}

/*
*** Default destructor
*/

Contact::~Contact(void) {
    return ;
}

/*
*** set functions
*/

void Contact::setFirstName(std::string a) {
    this->first_name = a;
}

void Contact::setLastName(std::string a) {
    this->last_name = a;
}

void Contact::setNickname(std::string a) {
    this->nickname = a;
}

void Contact::setLogin(std::string a) {
    this->login = a;
}

void Contact::setPostalAddress(std::string a) {
    this->postal_address = a;
}

void Contact::setEmailAddress(std::string a) {
    this->email_address = a;
}

void Contact::setPhoneNumber(std::string a) {
    this->phone_number = a;
}

void Contact::setBirthdayDate(std::string a) {
    this->birthday_date = a;
}

void Contact::setFavoriteMeal(std::string a) {
    this->favorite_meal = a;
}

void Contact::setUnderwearColor(std::string a) {
    this->underwear_color = a;
}

void Contact::setDarkestSecret(std::string a) {
    this->darkest_secret = a;
}

/*
*** get functions
*/

std::string Contact::getFirstName(void) {
    return (this->first_name);
}

std::string Contact::getLastName(void) {
    return (this->last_name);
}

std::string Contact::getNickname(void) {
    return (this->nickname);
}

std::string Contact::getLogin(void) {
    return (this->login);
}

/*
*** other methods of class
*/

void Contact::print_part(std::string s) {
    int space = s.length();

    if (space < 10)
        std::cout << std::string(10 - space, ' ') << s;
    else
    {
        for(int index = 0; index < 9; index++)
            std::cout << s[index];
        std::cout << '.';
    }
}

void Contact::print_cont_info(void) {
    std::cout << std::string(9, ' ') << index << '|';
    print_part(first_name);
    std::cout << '|';
    print_part(last_name);
    std::cout << '|';
    print_part(nickname);
    std::cout << std::endl;
}

void Contact::print_contact(void) {
    std::cout << "first_name : " << first_name << std::endl;
    std::cout << "last_name : " << last_name << std::endl;
    std::cout << "nickname : " << nickname << std::endl;
    std::cout << "login :" << login << std::endl;
    std::cout << "postal_address : " << postal_address << std::endl;
    std::cout << "email_address : " << email_address << std::endl;
    std::cout << "phone_number : " << phone_number << std::endl;
    std::cout << "birthday_date : " << birthday_date << std::endl;
    std::cout << "favorite_meal : " << favorite_meal << std::endl;
    std::cout << "underwear_color : " << underwear_color << std::endl;
    std::cout << "darkest_secret : " << darkest_secret << std::endl;
}
