//
// Created by tjooris on 7/22/25.
//

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <cstdlib>
#include <cstdio>
#include <string>

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook(const PhoneBook &other);
    PhoneBook& operator=(const PhoneBook &other);
    void addContact();
    void header();
    void menu();
    std::string get_prompt(const std::string &prompt);
    int getCurrentIndex();
    Contact getContact(int index);
    void displayContacts();
    void searchContact(int index);

private:
    Contact contacts[8];
    int current_index;
    int total_contacts;
};

#endif
