#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

using namespace std;

int stringToInt(const string& str, bool& success)
{
    success = false;
    if (str.empty())
        return 0;

    istringstream iss(str);
    int result;
    if (iss >> result && iss.eof())
    {
        success = true;
        return result;
    }
    return 0;
}

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
            bool conversion_success;
            int index = stringToInt(index_str, conversion_success);

            if (conversion_success)
            {
                phonebook.searchContact(index);
            }
            else
            {
                cout << "Error: Invalid index format" << endl;
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