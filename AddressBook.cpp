#include "AddressBook.h"

using namespace std;

AddressBook::AddressBook()
{
}

AddressBook::~AddressBook()
{
}

/**
 * This function sorts the address book by last name.
 * NOTE: The sorting is case insensitive
 */
bool AddressBook::SortByLastName(const Contact &A, const Contact &B)
{    
    string AFullName = A.FirstName, BFullName = B.FirstName;
    AFullName = A.LastName + AFullName;
    BFullName = B.LastName + BFullName;

    transform(AFullName.begin(), AFullName.end(), AFullName.begin(), ::toupper);
    transform(BFullName.begin(), BFullName.end(), BFullName.begin(), ::toupper);

    if (AFullName >= BFullName)
        {return false;}
    else
        {return true;}
}

/**
 * This function sorts the address book by first name.
 * NOTE: The sorting is case insensitive
 */
bool AddressBook::SortByFirstName(const Contact &A, const Contact &B)
{
    string AFullName = A.FirstName, BFullName = B.FirstName;
    AFullName = AFullName + A.LastName;
    BFullName = BFullName + B.LastName;

    transform(AFullName.begin(), AFullName.end(), AFullName.begin(), ::toupper);
    transform(BFullName.begin(), BFullName.end(), BFullName.begin(), ::toupper);

    if (AFullName >= BFullName)
        {return false;}
    else
        {return true;}
}

/**
 * This function adds an entry to the address book with or without a phone number.
 */
void AddressBook::AddEntry(const char* FirstName, const char* LastName, const char* PhoneNumber)
{
    this->Book.push_back(Contact(FirstName, LastName, PhoneNumber));
}

/**
 * This function removes an entry from the address book.
 * NOTE: it uses a lambda function to check whether the supplied first and last names
 * exactly match one in the book through the "find_if()" function. This always returns
 * an iterator, being the last, in case nothing is found, or the one relative to the
 * entry being removed. If the removal is unsuccessfull, it returns -1, otherwise it will
 * return 0.
 */
int AddressBook::RemoveEntry(const char* FirstName, const char* LastName)
{
    vector<Contact>::iterator it;

    auto Pred = [=](const Contact & c) 
    {
        return !strcmp(c.FirstName, FirstName) && !strcmp(c.LastName, LastName);
    };

    it = find_if(this->Book.begin(), this->Book.end(), Pred);
    
    if (it == this->Book.end())
        {return -1;}
    else
    {
        it = this->Book.erase(it);
        return 0; 
    }
}

/**
 * This function searches for an entry in the address book given a substring.
 * NOTE: it concatenates the first and last names to enable the search to work 
 * on both names at the same time. The search is also case insensitive.
 */
vector<Contact> AddressBook::FindEntries(string Substring)
{
    vector<Contact> Occurences;

    for (int i = 0; i < this->Book.size(); i++)
    {
        string FullName = this->Book[i].FirstName;
        FullName += " ";
        FullName += this->Book[i].LastName;

        transform(FullName.begin(), FullName.end(), FullName.begin(), ::toupper);
        transform(Substring.begin(), Substring.end(), Substring.begin(), ::toupper);

        if (FullName.find(Substring) != string::npos)
            {Occurences.push_back(this->Book[i]);}
    }

    return Occurences;
}

/**
 * This function prints the contents of the AddressBook.
 */
void AddressBook::Print()
{
    for (int i = 0; i < this->Book.size(); i++)
    {this->Book[i].Print();}
}

/**
 * This function sorts the address book.
 * NOTE: through the constant definitions in the classes' header file
 * it will chose whether the sort will be by last or first name.
 */
void AddressBook::Sort(int mode)
{
    switch(mode)
    {
        case SORT_FIRSTNAME:
            sort(this->Book.begin(), this->Book.end(), SortByFirstName);
            break;
        case SORT_LASTNAME:
            sort(this->Book.begin(), this->Book.end(), SortByLastName);
            break;
        default:
            cout << "Invalid mode for sorting function!" << endl;
    }
}