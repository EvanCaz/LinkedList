/*********************
 * Evan Cazares
 * Assignment: coding06
* doubly linked list with a head, no tail, and proper methods
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id, string* ptr){ // needs to deterine if we are creating first node in list or just creating next one
    // if adding at end, next needs to be null, if at the start prev needs to be null
    // find duplicates
    bool duplicate = false, sucess;
    if( id > 0 && !ptr->empty()){ // if id is 0 or greater and string is not empty...

        Node* newNode = new Node; // allocated memory for newnode struct
        newNode->data.id = id; // set data obj id in the new node to id
        newNode->data.data = *ptr; // set data obj data in the new node to dereference of ptr as it needs to own it

        if (head == NULL){ // determine if we are adding at the beggining
            head = newNode;
            newNode->prev = NULL; // nothing before it
            newNode->next = NULL; // since its the first and only one
            sucess = true; 
        } else if(head != NULL){ // if not the beggining...
            Node* current = head; // create postion marker and set postion as first node
            while(current->next != NULL){ // loop through list, comparing id's until thingy is found, if not found and no duplicate , add at end
                if(current->data.id > id && current->data.id != id) { // if the current node's id is greater than ours and no duplicates have been found...
                    // flag boolean value checked to prevent excess running
                    newNode->next = current; // since current is after we want the next pointer in our new node to point to it
                    newNode->prev = current->prev; // simiar, set pointer to previous node to the pointer of the previous node stored in the current node
                    current->prev->next = newNode; // set the node pointer next in the node before current to our new node
                    current->prev = newNode; // set prev point in the current node to our inserted node
                    sucess = true;
                    break; // break loop since we found it and dont want to run duplicate if statment
                } else if (current->data.id == id){ // if duplicate...
                    // retunr false, set duplicate to true
                    duplicate = true;
                    sucess = false;
                    break;
                    // we dont want to break because we want current to be set to the end node to be used in next if statment
                    // but if statment not used cuz dplicate = true so we can break;
                    // logic error maybe
                }
                current = current->next; // go to next node
            }
            // if it was never found and no duplicates, add at end
            if(duplicate == false){
                newNode->next = NULL;
                newNode->prev = current; // set to last node
                current->next = newNode; // set last node next pointer to our end
                sucess = true;
            }
        }
    }
    return sucess;
}

bool LinkedList::deleteNode(int id){
    Node* current = head;
    bool success = false;
    while(current->next != NULL){
        if (current->data.id == id){
            current->prev->next = current->next; // set the node before currents next pointer to the node after current
            current->next->prev = current->prev; // set the node after currents prev pointer to the node before current
            delete current->next;
            delete current->prev; // dont think i need this as i did not allocate memory for pointers in the struct, maybe just delete current
            delete current;
            success = true;
        }
        current = current->next;
    }
    return success;
}

bool LinkedList::getNode(int id, Data* data){
    Node* current = head;
    bool success = false;
    while(current->next != NULL){
        if(current->data.id == id){
            data->data = current->data.data;
            data->id = current->data.id;
            success = true;
        }
    }
    if (success == false){
        data->data = "";
        data->id = -1;
    }
    return success;
}

void LinkedList::printList(bool backward){
    std::cout << "Test&" << std::endl;
    return;
}

int LinkedList::getCount(){
    int counter = 0;
    // Node* current;
    // if (head != NULL){
    //     current = head;
    //     while(current->next != NULL){
    //     counter++;
    //     }
    // }
    return counter;

}
bool LinkedList::clearList(){
    return false;
}
bool LinkedList::exists(int id){
    return false;

}