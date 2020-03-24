//
// Created by bo_10 on 3/24/2020.
//
#include <iostream>
#include "List.h"
using std::cout;

List::List() {
    head = nullptr;
    curr = nullptr;
}

void List::add(int x) {
    NodePtr temp = new Node;
    temp->next = nullptr;
    temp->data = x;

    if (head != nullptr) {
        curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    else {
        head = temp;
    }

}

void List::show() {
    curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
}


int List::search_number(int x) {
    while (head != nullptr) {
        if (head->data == x) {
            return x;


        }
        else {
            head = head->next;
        }
    }

    return -1;


}



