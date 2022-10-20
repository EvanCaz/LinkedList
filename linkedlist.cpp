/*********************
 * Evan Cazares
 * Assignment: coding06
* doubly linked list with a head, no tail, and proper methods
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id, string* ptr){ // incosisten segmentation error
    bool duplicate = false, sucess = false, found = false, beggining = false, firstNode = false, go = true; // use flags to allocate memory after determining no duplicate
    // "go" used to execute the while loop at least once and until the und, do while doesnt cut it
    if( id > 0 && !ptr->empty()){ // if id is 0 or greater and string is not empty...
        Node* current = head; // set a marker
        if (current == NULL){ // if empty, set flag and dont run other code
            beggining = true;
        } else { // if not beginning
            while(go == true){  // repeat until marker is last node if not found id
                if (current->data.id == id){
                    duplicate = true;
                    sucess = false;
                    break;
                }
                if(current->data.id > id){
                    found = true;
                    break;
                }
                if(current->next == NULL){
                    go = false;
                } else {
                    go = true;
                    current = current->next;
                }
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

bool LinkedList::deleteNode(int id){ // does not work
    Node* current = head;
    bool success = false, go = true; // used to execute the while loop at least once and until the und, do while doesnt cut it
    // if(current == NULL){
    //     success = false;
    // } else {
    //     while(go == true){
    //         if(current->data.id == id){
    //             if(current->next != NULL){ // if not at tail
    //                 current->prev->next = current->next;
    //                 current->next->prev = current->prev;
    //                 delete current->next;
    //                 delete current->prev;
    //                 delete current;
    //             } else { // if at tail
    //                 current->prev->next = NULL;
    //                 delete current->next;
    //                 delete current->prev;
    //                 delete current;
    //             }
    //             } else {
    //                 if(current->next == NULL){
    //                     go = false;
    //                 } else {
    //                     go = true;
    //                     current = current->next;
    //                 }
    //             }
    //         }
    //     }
    return success;
}

bool LinkedList::getNode(int id, Data* data){
    Node* current = head;
    bool success = false, go = true; // used to execute the while loop at least once and until the und, do while doesnt cut it
    if(current == NULL){
        success = false;
    } else {
        while(go == true){
            if(current->data.id == id){
                success = true;
                data->data = current->data.data;
                data->id = current->data.id;
                break;
            }
            if(current->next == NULL){
                go = false;
            } else {
                go = true;
                current = current->next;
            }
        }
    }
    return success;
}

void LinkedList::printList(bool backward){
    Node* current = head;
    bool go = true; // used to execute the while loop at least once and until the und, do while doesnt cut it
    if(current == NULL){
        return;
    } else {
        while(go == true){
            if(backward == false){
                std::cout << current->data.id << " : " << current->data.data << std::endl; // for printing last node
            }
            if(current->next == NULL){
                go = false;
            } else {
                go = true;
                current = current->next;
            }
        }
        go = true;
        if(backward == true){
            while(go == true) {
                std::cout << current->data.id << " : " << current->data.data << std::endl; // for printing last node
                if(current->prev == NULL){
                    go = false;
                } else {
                    go = true;
                    current = current->prev;
                }
            }
        }
    }
}

int LinkedList::getCount(){
    Node* current = head;
    int nodes = 0;
    bool go = true; // used to execute the while loop at least once and until the und, do while doesnt cut it
    if(current == NULL){
        nodes = 0;
    } else {
        while(go == true){
            nodes++;
            if(current->next == NULL){
                go = false;
            } else {
                go = true;
                current = current->next;
            }
        }
    }
    return nodes;
}

bool LinkedList::clearList(){
    return false;
}
bool LinkedList::exists(int id){
    Node* current = head;
    bool go = true, success = false; // used to execute the while loop at least once and until the und, do while doesnt cut it
    if(current == NULL){
        success = false;
    } else {
        while(go == true){
            if(current->data.id == id){
                success = true;
                break;
            }
            if(current->next == NULL){
                go = false;
            } else {
                go = true;
                current = current->next;
            }
        }
    }
    return success;
}