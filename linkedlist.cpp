/*********************
 * Evan Cazares
 * Assignment: coding06
* doubly linked list with a head, no tail, and proper methods
**********************/

#include "linkedlist.h"

bool LinkedList::addNode(int id, string* ptr){ // needs to deterine if we are creating first node in list or just creating next one
    // if adding at end, next needs to be null, if at the start prev needs to be null
    // find duplicates
    bool duplicate, sucess;
    if( id > -1 && !ptr->empty()){ // if id is 0 or greater and string is not empty...
        Data* data;
        data->id = id;
        data->data = *ptr; // because the payload needs to own the information, not a refernece
        Node* newNode = new Node; // allocated memory for node
        if (head == NULL){ // determine if we are adding at the beggining
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = NULL; // because new head, nothing before it
            head = newNode;
            sucess = true;
        } else if(head != NULL){ // if not the beggining...
            Node* current = head->next; // create postion marker and set postion as first node and not the head
            while(current->next != NULL){ // loop through list, compaing id's until thingy is found, if not found, add at end
                if(current->data.id > id) {
                    // pefrom insertion before currnt, break while loop
                    newNode->next = current; // since current is after we want the next pointer in our new node to point to it
                    newNode->prev = current->prev; // simiar, set pointer to previous node to the pointer of the previous node stored in the current node
                    current->prev->next = newNode; // set the node pointer next in the node before current to our new node
                    current->prev = newNode; // set prev point in the current node to our inserted node
                    sucess = true;
                    break; // break loop since we found it
                } else if (current->data.id == id){ // if duplicate...
                    // retunr false, set duplicate to true
                    duplicate = true;
                    sucess = false;
                    // we dont want to break because we want current to be set to the end node to be used in next if statment
                }
                current = current->next; // go to next node
            }
            // if it was never found and no duplicates, add at end
            if(duplicate == false){
                //perform inseriton at the end
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
    return false;
}

bool LinkedList::getNode(int id, Data* data){
    return false;
}

void LinkedList::printList(bool backward){
    std::cout << "Test" << std::endl;
}

int LinkedList::getCount(){
    return 0;
}
bool LinkedList::clearList(){
    return false;
}
bool LinkedList::exists(int id){
    return false;
}