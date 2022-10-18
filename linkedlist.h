/*********************
 * Evan Cazares
 * Assignment: coding06
* doubly linked list with a head, no tail, and proper methods
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>


class LinkedList {
    private:
    Node *head; // pointer for first node, null when empty list/no list
    public: 
    LinkedList(){
        head = NULL;
    }
    // addNode, deleteNode, getNode, printList, getCount, clearList, exists
    // construcot and destrucot to allocate and deallocate memory
    bool addNode(int, string*);
    // hard, have to leave in sorted order, reattach, input validation, check to make sure there are no dupiclates and delete if so,
    // should be called insertNode

    bool deleteNode(int); // delete the node with specifed int, reattaching the prev and next nodes togethor
    bool getNode(int, Data*); 
    // just like pop or peek, pass method the node you want and an empty struct to hold the data in that node, get data, return that struct
    // and retunr true, if not found fill empty struct and return false
    void printList(bool = false);
    //print the list either forward or backward dependent on flag, defualt is forward
    int getCount();
    // get count each time called
    bool clearList();
    // deallocated and set head to null instead of the first node
    bool exists(int);
    // checks to see if given id corresponds with a node in the list

};




#endif