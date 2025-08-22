#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

use namespace std;

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

void PhoneBook::header() const {
    cout << "-----------------------------------" << endl;
    cout << "|    PhoneBook   d=====(￣▽￣*)b   |" << endl;
    cout << "-----------------------------------\n\n" << endl;
}

void PhoneBook::menu() const {
    cout << "   Tap one command" << endl;
    cout << "1. ADD\n" << endl;
    cout << "2. SEARCH\n" << endl;
    cout << "3. EXIT\n\n" << endl;
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
    throw runtime_error("Contact not found");
}

void searchContact(const string name) const {
    try {
        Contact contact = getContact(name);
        cout << "Contact found: " << contact.getFirstName() << " " << contact.getLastName() << endl;
        cout << "Nickname: " << contact.getNickname() << endl;
        cout << "Phone Number: " << contact.getPhoneNumber() << endl;
        cout << "Darkest Secret: " << contact.getDarkestSecret() << endl;
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    }
}

void PhoneBook::displayContacts() const
{

    if(total_contacts == 0)
    {
        cout << "No contacts available." << endl;
        return;
    }

	cout << "-------------------------------------------" << endl;
	cout << setw(10) << "Index" << "|"
         << setw(10) << "First Name" << "|"
         << setw(10) << "Last Name" << "|"
         << setw(10) << "Nickname" << "\n" << endl;
	cout << "-------------------------------------------" << endl;
    for (int i = 0; i < total_contacts; ++i)
    {
        cout << setw(10) << i << "|";
        cout << setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|";
        cout << setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|";
        cout << setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << "\n" << endl;
    }
    cout << "-------------------------------------------" << endl;
}

string PhoneBook::get_prompt(const string &prompt) const {
    string input;

    cout << prompt;
    while (true)
    {
        if (!getline(cin, input))
        {
            clear_input();
            continue;
        }
        if (cin.eof())
        {
            clear_input();
            cout << "\n";
            cout << prompt;
            continue;
        }
        if (input.empty())
        {
            cout << "Null input, retry\n";
            cout << prompt;
            continue;
        }
        return input;
    }
}

void PhoneBook::addContact(const PhoneBook &phonebook) {
    Contact new_contact;
    string input;

	system("clear");
	header();
    input = get_prompt("Enter First Name: ");
    new_contact.setFirstName(input);

    input = get_prompt("Enter Last Name: ");
    new_contact.setLastName(input);

    input = get_prompt("Enter Nickname: ");
    new_contact.setNickname(input);

    input = get_prompt("Enter Phone Number: ");
    new_contact.setPhoneNumber(input);

    input = get_prompt("Enter Darkest Secret: ");
    new_contact.setDarkestSecret(input);

    contacts[current_index] = new_contact;
    current_index = (current_index + 1) % 8;
    if (total_contacts < 8) {
        total_contacts++;
    }
}