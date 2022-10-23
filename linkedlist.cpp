/*********************
 * Evan Cazares
 * Assignment: coding06
* doubly linked list with a head, no tail, and proper methods
**********************/

#include "linkedlist.h"

// g++ -I ./ *cpp

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id, string* ptr){ // inconsistent segmentation error, have not shortened with functions cuz idk where error is happening
    bool sucess = false;
    if( id > 0 && !ptr->empty()){ // if id is 0 or greater and string is not empty...
        Node* current = head; // set a marker
        if(current == NULL){
            Node* newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *ptr;
            insertHead(newNode, &sucess);
            } else {
                    while(current != NULL && current->next != NULL && current->data.id < id){
                        current = current->next;
                    }
                    if(current->data.id != id){
                        Node* newNode = new Node;
                        newNode->data.id = id;
                        newNode->data.data = *ptr; 
                        if (current->prev == NULL && current->data.id > id){ // replacing head
                            replaceHead(current, newNode, id, &sucess);
                        } else if (current->next == NULL && id > current->data.id){ // add tail
                            insertTail(current, newNode, id, &sucess);
                        } else { // add midde
                            insertMiddle(current, newNode, &sucess, id);
                        }
                    }
        }
    }
    return sucess;
}


void LinkedList::insertHead(Node* newNode, bool* sucess){
    head = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
    *sucess = true;
}

void LinkedList::replaceHead(Node* current, Node* newNode, int id, bool* sucess){ // fails when the duplicate is the first id added, not sure why
    if(current->data.id != id){
        head = newNode;
        newNode->prev = NULL;
        newNode->next = current;
        current->prev = newNode;
        *sucess = true;
    }
}

void LinkedList::insertTail(Node* current, Node* newNode, int id, bool* sucess){
    if(current->data.id != id){
        if(current->next == NULL){}
        current->next = newNode;
        newNode->next = NULL;
        newNode->prev = current;
        *sucess = true;
    }
}

void LinkedList::insertMiddle(Node* current, Node* newNode, bool* sucess, int id){
    if(id != current->data.id){
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        *sucess = true;
    }
}



bool LinkedList::deleteNode(int id) {
  Node *current = head;
  bool success = false;
  if (id > 0 && current != NULL) {
    while (current && current->next && current->data.id != id) {
        current = current->next;
    }
    if (current->prev == NULL && current->data.id == id) {
        if(current->next == NULL){
            head = NULL;
            delete current;
            success = true;
        } else {
            head = current->next;
            current->next->prev = NULL;
            delete current;
            success = true;
        }
    } else if (current->next == NULL && current->data.id == id) {
        current->prev->next = NULL;
        delete current;
        success = true;
    } else if (current->prev && current->next) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        success = true;
    }
  }
  return success;
}

bool LinkedList::getNode(int id, Data* data){ // done
    Node* current = head;
    bool success = false; 
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

void LinkedList::printList(bool backward){ // done
    Node* current = head;
    int index = 1;
    while(current != NULL && current->next != NULL){
        if(backward == false) {
            std::cout << index << ": " << current->data.id << " : " << current->data.data << std::endl;
        }
        index++;
        current = current->next; // still want to run to get current to the end to be used in backwards
    }
    if(current){
        std::cout << index << ": " << current->data.id << " : " << current->data.data << std::endl; // prints remainder
    }
    if(backward == true){
        index -= 1;
        while(current != NULL && current->prev != NULL){
            current = current->prev;
            std::cout << index << ": " << current->data.id << " : " << current->data.data << std::endl;
            index--;
        }
    }
}

int LinkedList::getCount(){ // done
    Node* current = head;
    int nodes = 0;
    if(current != NULL){
        nodes++; // start at one cuz current = head
        while(current->next != NULL){
            current = current->next;
            nodes++;
        }
    }
    return nodes;
}

bool LinkedList::clearList(){ // have not done since i cant even delete one node yet
    Node* current = head;
    bool success = false;
    head = NULL;
    if(current != NULL){
        while(current->next != NULL){
            current = current->next;
            delete current->prev;
        }
        delete current; // delete remainder
        success = true;
    }
    return success;
}

bool LinkedList::exists(int id){ // done
    Node* current = head;
    bool success = false;
    while(success == false && current != NULL){
        if(current->data.id == id){
              success = true;
        }
        current = current->next;
    }
    return success;
}