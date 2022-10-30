#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

#include "Contact.h"

#define SORT_FIRSTNAME 0
#define SORT_LASTNAME 1

#ifndef ADDRESSBOOK_H // To avoid redefinition, an ifndef clause is included
#define ADDRESSBOOK_H
class AddressBook
{
private:
    static bool SortByLastName(const Contact &A, const Contact &B);
    static bool SortByFirstName(const Contact &A, const Contact &B);
public:
    std::vector<Contact> Book;
    AddressBook();
    ~AddressBook();
    void AddEntry(const char* FirstName, const char* LastName, const char* PhoneNumber = nullptr);
    int RemoveEntry(const char* FirstName, const char* LastName);
    std::vector<Contact> FindEntries(std::string Substring);
    void Print();
    void Sort(int mode);
};
#endif