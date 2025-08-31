//
// Created by tjooris on 7/22/25.
//

#include "Contact.hpp"

Contact::Contact() : firstname(""), lastname(""), nickname(""), phone_number(""), darkest_secret("")
{

}

Contact::~Contact()
{

}

Contact::Contact(const Contact &other)
    : firstname(other.firstname), lastname(other.lastname), nickname(other.nickname),
      phone_number(other.phone_number), darkest_secret(other.darkest_secret)
{

}

Contact& Contact::operator=(const Contact &other)
{
    if (this != &other) {
        firstname = other.firstname;
        lastname = other.lastname;
        nickname = other.nickname;
        phone_number = other.phone_number;
        darkest_secret = other.darkest_secret;
    }
    return *this;
}

void Contact::setFirstName(const std::string &first_name)
{
    firstname = first_name;
}

void Contact::setLastName(const std::string &last_name)
{
    lastname = last_name;
}

void Contact::setNickname(const std::string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phone_number)
{
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string &darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

std::string Contact::getFirstName() const
{
    return firstname;
}

std::string Contact::getLastName() const
{
    return lastname;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phone_number;
}

std::string Contact::getDarkestSecret() const
{
    return darkest_secret;
}
