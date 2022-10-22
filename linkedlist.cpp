/*********************
 * Evan Cazares
 * Assignment: coding06
* doubly linked list with a head, no tail, and proper methods
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id, string* ptr){ // inconsistent segmentation error, have not shortened with functions cuz idk where error is happening
    bool sucess = false;
    if( id > 0 && !ptr->empty()){ // if id is 0 or greater and string is not empty...
        Node* current = head; // set a marker
        if(current == NULL){
            sucess = true;
            Node* newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *ptr; // repetitive
            insertHead(newNode);
            } else {
                    while(current != NULL && current->next != NULL && current->data.id < id){
                        current = current->next;
                    }
                    if(current->data.id != id){
                        sucess = true;
                        Node* newNode = new Node;
                        newNode->data.id = id;
                        newNode->data.data = *ptr; // repetitive
                        if (current->prev == NULL){ // replacing head
                            replaceHead(current, newNode);
                        } else if (current->next == NULL){ // add tail
                            insertTail(current, newNode);
                        } else { // add midde
                            insertMiddle(current, newNode);
                        }
                    }
        }
    }   
    return sucess;
}


void LinkedList::insertHead(Node* newNode){
    head = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
}

void LinkedList::replaceHead(Node* current, Node* newNode){
    head = newNode;
    newNode->prev = NULL;
    newNode->next = current;
    current->prev = newNode;
}

void LinkedList::insertTail(Node* current, Node* newNode){
    current->next = newNode;
    newNode->next = NULL;
    newNode->prev = current;
}

void LinkedList::insertMiddle(Node* current, Node* newNode){
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
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

bool LinkedList::getNode(int id, Data* data){ // done
    Node* current = head;
    bool success = false; // used to execute the while loop at least once and until the und, do while doesnt cut it
    if(current == NULL){
        success = false;
    } else {
        while(current != NULL && success == false){
            if(current->data.id == id){
                data->data = current->data.data;
                data->id = current->data.id;
                success = true;
            }
            current = current->next;
        }
    }
    return success;
}

void LinkedList::printList(bool backward){ // needs shortenining
    Node* current = head;
    int index = 1;
    while(current != NULL && current->next != NULL){
        if(backward == false) {
            std::cout << index << ": " << current->data.id << " : " << current->data.data << std::endl;
        }
        index++;
        current = current->next;
    }
    if(backward == true){
        index -= 1;
        while(current != NULL && current->prev != NULL){
            std::cout << index << ": " << current->data.id << " : " << current->data.data << std::endl;
            index--;
            current = current->prev;
    }
}
}

int LinkedList::getCount(){ // done
    Node* current = head;
    int nodes = 0;
    if(current != NULL){
        nodes++; // start at one cuz current = head
        while(current != NULL && current->next != NULL){
            current = current->next;
            nodes++;
        }
    }
    return nodes;
}

bool LinkedList::clearList(){ // have not done since i cant even delete one node yet
    return false;
}
bool LinkedList::exists(int id){ // done, sike
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