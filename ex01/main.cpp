
#include "Contact.hpp"
#include "PhoneBook.hpp"

using namespace std;

int main()
{
    PhoneBook phonebook;
    string command;

    while (true)
    {
        phonebook.header();
        phonebook.menu();
        command = phonebook.get_prompt("Enter command: ");
        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.displayContacts();
            string index_str = phonebook.get_prompt("Enter contact index to view details: ");
            try {
                int index = stoi(index_str);
                phonebook.searchContact(index);
            } catch (const invalid_argument &e) {
                cout << "Error: Invalid index format" << endl;
            } catch (const out_of_range &e) {
                cout << "Error: Index out of range" << endl;
            }
        }
        else if (command == "EXIT")
        {
            cout << "Exiting PhoneBook. Goodbye!" << endl;
            break;
        }
    }
    return 0;
}