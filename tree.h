#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Simranjit Bhella
//2/22/2022
//CS163
//The purpose of this code is to set up the structs and classes required for the binary search tree program.
//These include the item struct with information about the products, the node struct, and the tree class,
//The node struct is a used for the search tree and has a left and right pointer as well as an item object.
//The tree class's public functions include functions to add items, display all, display by keyword, retrieve by keyword,
//remove by keyword, and display all items of a certain type. Its private member is the root of the tree.

//Item stuct with info on the items
struct item {
    char * keyword;
    char * description;
    char * type;
    char * platform;
    char * rating;
};

//Node struct with an item object and left and right pointers
struct node {
    struct item this_item;
    node * left;
    node * right;
};

//tree class will set up the tree and manage seaches and edits
class tree {
    public:
        tree(); //hashtable class constructor
        ~tree(); //hashtable class destructor
        int treedestructor(node *&tmp); //function to recursivly delete the tree
        int additem(item * &to_add); //function to call recursive add item function
        int additemR(node * &tmp, item * &to_add); //function to add an item to the tree
        int displayall(); //function to call recursive display all function
        int displayallR(node * &tmp); //function to display all
        int displaymatch(char * to_find); //function to call display item by keyword function
        int displaymatchR(node * &tmp, char * to_find); //function to display item by keyword
        int retrivematch(char * to_find, item * &retrieve); //function to call retrieve item by keyword function
        int retrivematchR(node * &root, char * to_find, item * &retrieve); //function to retrieve item by keyword
        int removeitem(char * to_remove); //function to call remove item by keyword function
        int removeitemR(node * &root,char * to_remove); //function to remove item by keyword
        int displaytype(char * to_find); //function to call find item by keyword function
        int displaytypeR(node * &root, char * to_find); //function to find item by keyword
    private:
        node * root; //the root of the tree
};