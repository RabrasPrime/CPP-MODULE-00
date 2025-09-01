#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

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

void PhoneBook::header()
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|    PhoneBook   d=====(￣▽￣*)b   |" << std::endl;
    std::cout << "-----------------------------------\n" << std::endl;
}

void PhoneBook::menu()
{
    std::cout << "   Tap one command" << std::endl;
    std::cout << "1. ADD\n" << std::endl;
    std::cout << "2. SEARCH\n" << std::endl;
    std::cout << "3. EXIT\n" << std::endl;
}

Contact PhoneBook::getContact(int index) {
    if (index < 0 || index >= this->total_contacts) {
        throw std::runtime_error("Error: Invalid index");
    }
    return this->contacts[index];
}

void PhoneBook::searchContact(int index)
{
    try {
        Contact contact = getContact(index);
        std::cout << "Contact found: " << contact.getFirstName() << " " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}

void PhoneBook::displayContacts()
{
    if(total_contacts == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < total_contacts; ++i)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << "\n" << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
}

std::string PhoneBook::get_prompt(const std::string &prompt)
{
    std::string input;

    std::cout << prompt;
    while (true)
    {
        if (!std::getline(std::cin, input))
        {
            std::cin.clear();
            clearerr(stdin);
            continue;
        }
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            std::cout << "\n";
            std::cout << prompt;
            continue;
        }
        if (input.empty())
        {
            std::cout << "Null input, retry\n";
            std::cout << prompt;
            continue;
        }
        return input;
    }
}

void PhoneBook::addContact() {
    Contact new_contact;
    std::string input;

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
