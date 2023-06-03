#pragma once
#include "Guest.h"
#include <iostream>



class Queue
{

private:

    class Node {
    public:
        Guest guest;
        Node* next;

        Node(const Guest& guest) : guest(guest), next(nullptr) {}
    };

    Node* head = NULL;
    Node* tail;


public:
    Queue() : head(nullptr), tail(nullptr) {}


    void addGuest(const Guest& guest);
    Guest dequeue();
    //Node getfront();
    bool isEmpty();


    void printGuests();
};
