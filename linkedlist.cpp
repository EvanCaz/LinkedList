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
    bool duplicate = false, sucess = false, found = false, beggining = false;
    if( id > -1 && !ptr->empty()){ // if id is 0 or greater and string is not empty...
        Node* current = head; // set a marker
        if (current == NULL){ // if we are at the begininng set a flag to true
            beggining = true;
        } else { // if not beginning
            while(current->next != NULL){  // repeat until marker is last node if not found things
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
                    newNode->prev = current;
                    newNode->next = NULL;
                    current->next = newNode;
                    sucess = true;
                }
            }
    }
    return sucess;
}

bool LinkedList::deleteNode(int id){ // wrong
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
        current = current->next;
    }
    if (success == false){
        data->data = "";
        data->id = -1;
    }
    return success;
}

void LinkedList::printList(bool backward){
    Node* current = head;
    if(current == NULL){
        return; // only one return statment, stops cuz nothing to print
        
    } else if(backward == true) { // set current to the end and go backwards
        while(current->next != NULL){
            current = current->next;
        }    
        while(current->prev != NULL){
            std::cout << current->data.id << " : " << current->data.data << std::endl;
            current = current->prev;
        }
    } else if (backward == false){ // just start at begginnig
        while(current->next != NULL){
            std::cout << current->data.id << " : " << current->data.data << std::endl;
            current = current->next;
        }
    }
}

int LinkedList::getCount(){
    Node* current = head;
    int counter;
    if(current == NULL){
        counter = 0;
    } else {
        while(current->next != NULL){
            counter++;
            current = current->next;
        }
    }
    return counter;
}

bool LinkedList::clearList(){
    return false;
}
bool LinkedList::exists(int id){
    return false;

}