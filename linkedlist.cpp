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
        Node* current = head; // set a mar  ker
        if(current == NULL){
            sucess = true;
            Node* newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *ptr; // repetitive
            insertHead(head, newNode);
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
                            replaceHead(head, current, newNode);
                        } else if (current->next == NULL){ // add tail
                            current->next = newNode;
                            newNode->next = NULL;
                            newNode->prev = current;
                        } else { // add midde
                            newNode->next = current;
                            newNode->prev = current->prev;
                            current->prev->next = newNode;
                            current->prev = newNode;
                        }
                    }
        }
    }
    return sucess;
}

void LinkedList::insertHead(Node* head, Node* newNode){
    head = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
}

void LinkedList::replaceHead(Node* head, Node* current, Node* newNode){
    head = newNode;
    newNode->prev = NULL;
    newNode->next = current;
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
//     Node* current = head;
//     bool go = true; // used to execute the while loop at least once and until the und, do while doesnt cut it
//     if(current == NULL){
//         return;
//     } else {
//         while(go == true){
//             if(backward == false){
//                 std::cout << current->data.id << " : " << current->data.data << std::endl; // for printing last node
//             }
//             if(current->next == NULL){
//                 go = false;
//             } else {
//                 go = true;
//                 current = current->next;
//             }
//         }
//         go = true;
//         if(backward == true){
//             while(go == true) {
//                 std::cout << current->data.id << " : " << current->data.data << std::endl; // for printing last node
//                 if(current->prev == NULL){
//                     go = false;
//                 } else {
//                     go = true;
//                     current = current->prev;
//                 }
//             }
//         }
//     }
 }

int LinkedList::getCount(){ // done
    Node* current = head;
    int nodes = 0;
    bool go = true; // used to execute the while loop at least once and until the und, do while doesnt cut it
    if(current != NULL){
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
bool LinkedList::exists(int id){ // done
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