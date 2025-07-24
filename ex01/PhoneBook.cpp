//
// Created by tjooris on 7/22/25.
//

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_index(0), total_contacts(0) {}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook &other)
    : current_index(other.current_index), total_contacts(other.total_contacts) {
    for (int i = 0; i < 8; ++i) {
        contacts[i] = other.contacts[i];
    }
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other) {
    if (this != &other) {
        current_index = other.current_index;
        total_contacts = other.total_contacts;
        for (int i = 0; i < 8; ++i) {
            contacts[i] = other.contacts[i];
        }
    }
    return *this;
}


void PhoneBook::addContact(const Contact &contact) {
    contacts[current_index] = contact;
    current_index = (current_index + 1) % 8;
    if (total_contacts < 8) {
        total_contacts++;
    }
}

Contact getContact(const string name) const
{
    for (int i = 0; i < total_contacts; ++i)
    {
        if (contacts[i].getFirstName() == name || contacts[i].getLastName() == name || contacts[i].getNickname() == name)
        {
            return contacts[i];
        }
    }
    throw std::runtime_error("Contact not found");
}

void searchContact(const string name) const {
    try {
        Contact contact = getContact(name);
        cout << "Contact found: " << contact.getFirstName() << " " << contact.getLastName() << endl;
        cout << "Nickname: " << contact.getNickname() << endl;
        cout << "Phone Number: " << contact.getPhoneNumber() << endl;
        cout << "Darkest Secret: " << contact.getDarkestSecret() << endl;
    } catch (const std::runtime_error &e) {
        cout << e.what() << endl;
    }
}

void PhoneBook::displayContacts() const {
    cout << "Contacts in PhoneBook:" << endl;
    for (int i = 0; i < total_contacts; ++i) {
        cout << i + 1 << ". " << contacts[i].getFirstName() << " "
             << contacts[i].getLastName() << " ("
             << contacts[i].getNickname() << ")" << endl;
    }
}

void PhoneBook::clearContacts()
{

}