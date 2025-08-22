//
// Created by tjooris on 7/22/25.
//

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <cstdlib>
#include <cstdio>

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        PhoneBook(const PhoneBook &other);
        PhoneBook& operator=(const PhoneBook &other);
        void addContact(const PhoneBook &phonebook);
		void header() const;
		void menu() const;
        string get_prompt(const string &prompt) const;
        int getTotalContacts();
        int getCurrentIndex();
        Contact getContact(int index);
        void displayContacts() const;
        void searchContact(string name) const;

    private:
        Contact contacts[8];
		int current_index;
        int total_contacts;
};

#endif
