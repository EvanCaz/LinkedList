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
    bool duplicate = false, sucess = false, found = false, beggining = false; // use flags to allocate memory after determining no duplicate
    if( id > 0 && !ptr->empty()){ // if id is 0 or greater and string is not empty...
        Node* current = head; // set a marker
        if (current == NULL){ // if we are at the begininng set a flag to true
            beggining = true;
        } else { // if not beginning
            while(current->next != NULL){  // repeat until marker is last node if not found id
                if (current->data.id == id){
                    duplicate = true;
                    sucess = false;
                    break;
                }
                if(current->data.id > id){
                    found = true;
                    break;
                }
                current = current->next;
            }
        }
            if(duplicate == false){
                Node* newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *ptr;
                if (beggining == true){ // adding new head
                    head = newNode;
                    newNode->prev = NULL;
                    newNode->next = NULL;
                    sucess = true;
                } else if(beggining == false && found == true){ // found inside the list
                    newNode->next = current;
                    newNode->prev = current->prev;
                    current->prev->next = newNode;
                    current->prev = newNode;
                    sucess = true;
                } else if (beggining == false && found == false){// adding tail
                    if (current->data.id == id){ // need this incase list has only one node and next id is a duplicate, logic flaw not sure how to solve
                    duplicate = true;
                    sucess = false;
                    } else {
                        newNode->prev = current;
                    newNode->next = NULL;
                    current->next = newNode;
                    sucess = true;
                    }
                }
            }
    }
    return sucess;
}

bool LinkedList::deleteNode(int id){ // wrong
    Node* current = head;
    bool success = false;
    if(id > -1){
        do
        {
            if(current->data.id == id){
                delete current->prev;
                delete current->next;
                delete current;
                success = true;
                break;
            }
            current = current->next;
        } while (current->next != NULL);
    }
    return success;
}

bool LinkedList::getNode(int id, Data* data){
    Node* current = head;
    bool success = false;
    // while(current->next != NULL){
    //     if(current->data.id == id){
    //         data->data = current->data.data;
    //         data->id = current->data.id;
    //         success = true;
    //     }
    //     current = current->next;
    // }
    // if (success == false){
    //     data->data = "";
    //     data->id = -1;
    // }
    return success;
}

void LinkedList::printList(bool backward){
    
}

int LinkedList::getCount(){
    Node* current = head;
    int nodes = 0;
    if(current == NULL){
        nodes = 0;
    } else {
        while (current->next != NULL){
            nodes++;
            current = current->next;
        }
    }
    return nodes;
}

bool LinkedList::clearList(){
    return false;
}
bool LinkedList::exists(int id){
    return false;

}