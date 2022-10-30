#include <iostream>

/**
 * This struct defines what a Contact is, with its first and last name, as well as a phone number.
 * Should there be any need in the future to add new fields, it can be done through here and the previous
 * instances will still be compatible.
 */
#ifndef CONTACT_H // To avoid redefinition, an ifndef clause is included
#define CONTACT_H
class Contact
{
    private:

    public:
        const char* FirstName;
        const char* LastName;
        const char* PhoneNumber = nullptr;

    Contact()
    {
    }

    Contact(const char* _FirstName, const char* _LastName, const char* _PhoneNumber = nullptr)
    {
        FirstName = _FirstName;
        LastName = _LastName;
        PhoneNumber = _PhoneNumber;
    }

    void Print();
};
#endif