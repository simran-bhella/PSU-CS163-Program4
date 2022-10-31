#include "tree.h"
//Simranjit Bhella
//2/25/2022
//CS163
//The purpose of this file is to implement the functions from tree.h:
//tree(); //hashtable class constructor
//~tree(); //hashtable class destructor
//int additem(item * to_add); //function to call recursive add item function
//int additemR(node * root, item * to_add); //function to add an item to the tree
//int displayall(); //function to call recursive display all function
//int displayallR(node * root); //function to display all
//int displaymatch(char * to_find); //function to call display item by keyword function
//int displaymatchR(node * root, char * to_find); //function to display item by keyword
//int retrivematch(char * to_find, item * retrieve); //function to call retrieve item by keyword function
//int retrivematchR(char * to_find, item * retrieve); //function to retrieve item by keyword
//int removeitem(char * to_remove); //function to call remove item by keyword function
//int removeitemR(char * to_remove); //function to remove item by keyword
//int displaytype(char * to_find); //function to call find item by keyword function
//int displaytypeR(char * to_find); //function to find item by keyword
//As ADT classes, all function do not directly interact with the appliction (except for display functionality).
//ALl functions besides constructor and destructor return 0 or 1 to announce failure or success.

tree::tree() {
    root = new node();
}

tree::~tree() {
    //call recursive destructor
    treedestructor(root);
}

//recursive destructor to delete each node in the tree
int tree::treedestructor(node *&tmp) {
    if (tmp) {
        treedestructor(tmp->left);
        treedestructor(tmp->right);
        delete tmp;
    }
}

//Wrapper function
int tree::additem(item *&to_add) {
    return(additemR(root, to_add));
}


int tree::additemR(node * &tmp, item *&to_add) {
    if (!to_add) {
        return 0;
    }

    //if there is no data, add the data and unwind.
    if (!tmp->this_item.keyword) {
        tmp->this_item.keyword = new char[strlen(to_add->keyword) + 1];
        strcpy(tmp->this_item.keyword, to_add->keyword);

        tmp->this_item.description = new char[strlen(to_add->description) + 1];
        strcpy(tmp->this_item.description, to_add->description);

        tmp->this_item.type = new char[strlen(to_add->type) + 1];
        strcpy(tmp->this_item.type, to_add->type);

        tmp->this_item.platform = new char[strlen(to_add->platform) + 1];
        strcpy(tmp->this_item.platform, to_add->platform);

        tmp->this_item.rating = new char[strlen(to_add->rating) + 1];
        strcpy(tmp->this_item.rating, to_add->rating);

        return 1;
    }

    //If keyword to add is less than current keyword, move left.
    if (strlen(to_add->keyword) < strlen(tmp->this_item.keyword)) {
        if (!tmp->left) { //if no node create node
            tmp->left = new node();
        }
        return additemR(tmp->left, to_add);
    }


    //otherwise, move right
    if (!tmp->right) { //if no node create node
        tmp->right = new node();
    }
    return additemR(tmp->right, to_add);

    return 1;
}

//Wrapper function
int tree::displayall() {
    return displayallR(root);
}

int tree::displayallR(node * &tmp){
    if (!tmp) {
        return 0;
    }

    displayallR(tmp->left); //recursivly call all left nodes,
    cout << "keyword: " << tmp->this_item.keyword << endl;
    cout << "description: " << tmp->this_item.description << endl;
    cout << "type: " << tmp->this_item.type << endl;
    cout << "platform: " << tmp->this_item.platform << endl;
    cout << "rating: " << tmp->this_item.rating << endl;
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    displayallR(tmp->right); //then recursivly call all right nodes

    return 1;
}

//Wrapper function
int tree::displaymatch(char *to_find) {
    return displaymatchR(root, to_find);
}

int tree::displaymatchR(node * &tmp, char * to_find) {
    if (!tmp) {
        return 0;
    }

    //if match, display and unwind
    if (strcmp(tmp->this_item.keyword, to_find) == 0) {
        cout << "keyword: " << tmp->this_item.keyword << endl;
        cout << "description: " << tmp->this_item.description << endl;
        cout << "type: " << tmp->this_item.type << endl;
        cout << "platform: " << tmp->this_item.platform << endl;
        cout << "rating: " << tmp->this_item.rating << endl;
        return 1;
    }

    //if to find is less than current, go left
    if (strlen(to_find) < strlen(tmp->this_item.keyword)) {
        return displaymatchR(tmp->left, to_find);
    }

    //otheriwse, go right
    return displaymatchR(tmp->right, to_find);

}

//Wrapper function
int tree::retrivematch(char *to_find, item *&retrieve){
    return retrivematchR(root, to_find, retrieve);
}

//works exactly the same as the previous function
int tree::retrivematchR(node * &root, char *to_find, item *&retrieve) {
    if (!root) {
        return 0;
    }

    if (strcmp(root->this_item.keyword, to_find) == 0) {
        retrieve->keyword = new char[strlen(root->this_item.keyword) + 1];
        strcpy(retrieve->keyword, root->this_item.keyword);

        retrieve->description = new char[strlen(root->this_item.description) + 1];
        strcpy(retrieve->description, root->this_item.description);

        retrieve->type = new char[strlen(root->this_item.type) + 1];
        strcpy(retrieve->type, root->this_item.type);

        retrieve->platform = new char[strlen(root->this_item.platform) + 1];
        strcpy(retrieve->platform, root->this_item.platform);

        retrieve->rating = new char[strlen(root->this_item.rating) + 1];
        strcpy(retrieve->rating, root->this_item.rating);
        return 1;
    }

    if (strlen(to_find) < strlen(root->this_item.keyword)) {
        return retrivematchR(root->left, to_find, retrieve);
    }

    return retrivematchR(root->right, to_find, retrieve);

}

//Wrapper function
int tree::removeitem(char *to_delete) {
    return (removeitemR(this->root, to_delete));
} //function to call remove item by keyword function

int tree::removeitemR(node *&tmp, char *to_delete) {
    if (!tmp) {
        return 0;
    }

    // if match delete and unwind
    if (strcmp(tmp->this_item.keyword, to_delete) == 0) {

        //if right node exists, promote it and delete old
        if(tmp->right) {
            node* left = new node();
            node * to_delete = new node();

            left = tmp->left;
            to_delete = tmp;

            tmp = tmp->right;
            tmp->left = left;

            delete to_delete;

        }
        //else if left node exists, promote it and delete old
        else if (tmp->left){
            node * to_delete = new node();
            to_delete = tmp;
            tmp = tmp->left;
            delete to_delete;
        }

        //else, delete node
        else {
            delete tmp;
        }

        return 1;
    }

    if (strlen(to_delete) < strlen(tmp->this_item.keyword)) {
        return removeitemR(tmp->left, to_delete);
    }

    return removeitemR(tmp->right, to_delete);


    return 0;
}

//Wrapper function
int tree::displaytype(char *to_find) {
    return displaytypeR(root, to_find);
}

//works just like display all function with an extra if statement.
int tree::displaytypeR(node *&tmp, char *to_find) {
    if (!tmp) {
        return 0;
    }

    displaytypeR(tmp->left, to_find);
    if (strcmp(to_find, tmp->this_item.type) == 0) {z
        cout << "keyword: " << tmp->this_item.keyword << endl;
        cout << "description: " << tmp->this_item.description << endl;
        cout << "type: " << tmp->this_item.type << endl;
        cout << "platform: " << tmp->this_item.platform << endl;
        cout << "rating: " << tmp->this_item.rating << endl;
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    displaytypeR(tmp->right, to_find);

    return 1;

}