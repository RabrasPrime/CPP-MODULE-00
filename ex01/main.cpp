#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

int stringToInt(const std::string& str, bool& success)
{
    success = false;
    if (str.empty())
        return 0;

    std::istringstream iss(str);
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
    std::string command;

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
            std::string index_str = phonebook.get_prompt("Enter contact index to view details: ");
            bool conversion_success;
            int index = stringToInt(index_str, conversion_success);

            if (conversion_success)
            {
                phonebook.searchContact(index);
            }
            else
            {
                std::cout << "Error: Invalid index format" << std::endl;
            }
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        }
    }
    return 0;
}
