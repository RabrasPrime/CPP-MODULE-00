//
// Created by tjooris on 7/22/25.
//

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

using namespace std;

class Contact
{
    public:
        Contact();
        ~Contact();
        Contact(const Contact &other);
        Contact& operator=(const Contact &other);
        void setFirstName(const string &first_name);
        void setLastName(const string &last_name);
        void setNickname(const string &nickname);
        void setPhoneNumber(const string &phone_number);
        void setDarkestSecret(const string &darkest_secret);

        string getFirstName() const;
        string getLastName() const;
        string getNickname() const;
        string getPhoneNumber() const;
        string getDarkestSecret() const;
    private:
        string firstname;
        string lastname;
        string nickname;
        string phone_number;
        string darkest_secret;
};



#endif //CONTACT_HPP
