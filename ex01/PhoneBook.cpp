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
