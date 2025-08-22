
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    string command;

    phonebook.header();
    while (true) {
        phonebook.menu();
        cout << "Enter command: ";
        if (!getline(cin, command)) {
            if (cin.eof()) {
                cout << "\nExiting program." << endl;
                break;
            }
            cin.clear();
            continue;
        }
        if (command == "ADD") {
            phonebook.addContact(phonebook);
        } else if (command == "SEARCH") {
            phonebook.displayContacts();
            string name = phonebook.get_prompt("Enter the first name, last name, or nickname of the contact to search: ");
            phonebook.searchContact(name);
        } else if (command == "EXIT") {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    return 0;
}