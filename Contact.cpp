#include "Contact.h"

using namespace std;

/**
 * This function prints the contents of a Contact.
 */
void Contact::Print()
{
    cout << "First name: " << this->FirstName << endl;
    cout << "Last name: " << this->LastName << endl;
    if (this->PhoneNumber != nullptr)
        {cout << "Phone number: " << this->PhoneNumber << endl;}
}