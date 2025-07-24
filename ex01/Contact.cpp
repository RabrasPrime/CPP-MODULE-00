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

void Contact::setFirstName(const string &first_name)
{
    firstname = first_name;
}

void Contact::setLastName(const string &last_name)
{
    lastname = last_name;
}

void Contact::setNickname(const string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const string &phone_number)
{
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(const string &darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

string Contact::getFirstName() const
{
    return firstname;
}

string Contact::getLastName() const
{
    return lastname;
}

string Contact::getNickname() const
{
    return nickname;
}

string Contact::getPhoneNumber() const
{
    return phone_number;
}

string Contact::getDarkestSecret() const
{
    return darkest_secret;
}
