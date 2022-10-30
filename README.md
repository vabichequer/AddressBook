# FoundryTest
Small repository hosting the test done for Foundry

# Foundry Test
Small repository hosting the test done for Foundry

# How to build this project
In order to compile this project, navigate to the folder this project is in and utilize the command 
```bash 
g++ main.cpp Contact.cpp AddressBook.cpp -o main -std=c++14
```

# Initial thoughts
Considering sorting and large-scale data managing, the three most viable options to implement this program are a vector, a BST or a hash table.

A vector, although having better data locality, has problems when inserting and deleting due to moving the position back and forth.

A hash table is faster to search, but has issues with duplicate values and as well as sorting. It also has a definite size, which means that it will either be wasteful on the long run or need to be modified. A multimap could be used to sort the duplicate values, but it would take more time to implement.

BST on the other hand is flexible, allows for a virtual infinite number of cases and has clear sort, search and insert/delete methods. This is the preffered approach, but has no ready-to-use implementation in C++.

Due to the time constrains, I'm choosing an STL vector as the container for the address book.

# Shortcomings and future improvements
- Searches could’ve been optimized by making them binary
- Other alphabets can be an exception
- Transform is a slow method to translate it to upper case. It could’ve been done by decreasing the value of lower case characters by 32 through a table
- Sorting could be tied to a status variable, which would track changes to the address book. If there are no changes and the address book is sorted, there is no need to do it again. The only exception is if the sorting method mismatches the one last used on the book.
- With a separate structure for the contact type, an image can be easily added as just another field
- Pretty much all three approaches are safe from a multithreaded point of view, as long as the proper locks are enforced, since memory will be shuffling and references can get lost if no locks are in place.
- The better memory management of C++17 could improve the memory usage of a hash table.
- The introduction of coroutines in C++20 could aid in some scenarios, as this can be an event-driven application in the future
