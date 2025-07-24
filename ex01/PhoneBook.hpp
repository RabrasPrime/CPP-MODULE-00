//
// Created by tjooris on 7/22/25.
//

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
        PhoneBook(const PhoneBook &other);
        PhoneBook& operator=(const PhoneBook &other);
        int current_index;
        void addContact(const Contact &contact);
        Contact getContact(int index);
        void displayContacts() const;
        void searchContact(string name) const;
        void clearContacts();

    private:
        Contact contacts[8];
        int total_contacts;
};

#endif
