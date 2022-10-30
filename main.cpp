#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    // Creation of the address book
    AddressBook Book;

    // Addition of the first 3 entries
    cout << "Adding four entries..." << endl;

    Book.AddEntry("Vicenzo", "Abichequer");
    Book.AddEntry("Jamile", "Sbichequer", "99177088");
    Book.AddEntry("Marina", "Abichequer");
    Book.AddEntry("Ana", "Paula Schulze");

    cout << endl << "Printing the entries..." << endl;

    // Check the contents of the address book
    Book.Print();

    cout << endl << "Removing the first entry named 'Vicenzo'..." << endl;

    // Removes an entry and checks if it was successfull through the return value
    if (Book.RemoveEntry("Vicenzo", "Abichequer") == -1)
        {cout << "Entry not found!" << endl;}
    else
        {cout << "Entry deleted successfully." << endl;}
    
    // Check the contents of the address book
    Book.Print();

    cout << endl << "Sorting address book by first name..." << endl;

    // Sort the address book by first name
    Book.Sort(SORT_FIRSTNAME);

    cout << endl << "Sorted address book:" << endl;

    // Check the contents of the address book
    Book.Print();
    
    cout << endl << "Sorting address book by last name..." << endl;

    // Sort the address book by first name
    Book.Sort(SORT_LASTNAME);

    cout << endl << "Sorted address book:" << endl;

    // Check the contents of the address book
    Book.Print();

    cout << endl << "Search for entries matching a 'Abi' in the address book..." << endl;

    // Search for entries matching a substring in the address book
    vector<Contact> SearchResult = Book.FindEntries("Abi");
    
    cout << endl << "Entries found:" << endl;

    // Check the results of the search
    for (int i = 0; i < SearchResult.size(); i++)
    {SearchResult[i].Print();}
}