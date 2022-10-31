#include "tree.h"
//Simranjit Bhella
//2/11/2022
//CS163
//The purpose of this code is to have a testing application for the ADT that is built in tree.h with the defined functions in tree.cpp.
//In this code under function main, this testing takes place through a dummy application with a user nav menu that allows for the testing of different functions.


int main() {
    int size = 100;
    int loop = 0;
    int menu = 0;
    tree *bst = new tree;

    do {
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Please choose an option below: " << endl;
        cout << "[1] Add an item to the tree" << endl;
        cout << "[2] Display whole tree" << endl;
        cout << "[3] Display by keyword match" << endl;
        cout << "[4] Retrieve by keyword match" << endl;
        cout << "[5] Remove by keyword match" << endl;
        cout << "[6] Display by type" << endl;
        cout << "[Anything Else] Quit the program" << endl << endl;
        cin >> menu;
        cin.ignore(100, '\n');

        //if user wants to add an item to the table
        if (menu == 1) {

            item * to_add = new item;

            cout<< "Enter product keyword: ";
            to_add->keyword = new char[size];
            cin.get(to_add->keyword, size,'\n');
            cin.ignore(100, '\n');

            cout<< "Enter product description: ";
            to_add->description = new char[size];
            cin.get(to_add->description, size,'\n');
            cin.ignore(100, '\n');

            cout<< "Enter product type: ";
            to_add->type = new char[size];
            cin.get(to_add->type, size,'\n');
            cin.ignore(100, '\n');

            cout<< "Enter product platform: ";
            to_add->platform = new char[size];
            cin.get(to_add->platform, size,'\n');
            cin.ignore(100, '\n');

            cout<< "Enter product rating: ";
            to_add->rating = new char[size];
            cin.get(to_add->rating, size,'\n');
            cin.ignore(100, '\n');

            int status = bst->additem(to_add);
            if (!status) {
                cout << "Adding item to tree failed" << endl;
            }
        }

            //if user wants to display the whole table;
        else if (menu == 2) {
            int status = bst->displayall();

            if (!status) {
                cout << "Displaying tree failed" << endl;
            }
        }

            //if user wants to display by keyword match
        else if (menu == 3) {
            cout << "Please enter the keyword of the item you would like displayed: ";
            char to_find[size];
            cin.get(to_find, size, '\n');
            cin.ignore(100, '\n');

            int status = bst->displaymatch(to_find);

            if (!status) {
                cout << "Loading items to table failed" << endl;
            }
        }

            //if user wants to retrieve item by keyword match
        else if (menu == 4) {
            item * retrieve= new item();
            cout << "Please enter the keyword of the item you would like retrieved: ";
            char to_find[size];
            cin.get(to_find, size, '\n');
            cin.ignore(100, '\n');


            int status = bst->retrivematch(to_find,retrieve);
            cout << "Retrieved object description: " << retrieve->description << endl;

            if (!status) {
                cout << "Retrieving item failed" << endl;
            }
        }

        //If user wants to remove item
        else if (menu == 5) {
            cout << "Please enter the keyword of the item you would like to remove: ";
            char to_remove[size];
            cin.get(to_remove, size, '\n');
            cin.ignore(100, '\n');


            int status = bst->removeitem(to_remove);

            if (!status) {
                cout << "Removing item failed" << endl;
            }
        }

        //If user wants to display by type
        else if (menu == 6) {
            cout << "Please enter the type of item you want displayed: ";
            char to_find[size];
            cin.get(to_find, size, '\n');
            cin.ignore(100, '\n');

            int status = bst->displaymatch(to_find);

            if (!status) {
                cout << "Loading items to table failed" << endl;
            }
        }

            //If anything else then change quite loop
        else {
            loop = 1;
        }
    } while (loop != 1);
}


