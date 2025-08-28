//
// Created by tjooris on 7/22/25.
//

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
public:
    Contact();
    ~Contact();
    Contact(const Contact &other);
    Contact& operator=(const Contact &other);
    void setFirstName(const std::string &first_name);
    void setLastName(const std::string &last_name);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phone_number);
    void setDarkestSecret(const std::string &darkest_secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

#endif //CONTACT_HPP
