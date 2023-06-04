#pragma once
#include "Guest.h"
#include <iostream>
#include <vector>


class Queue
{

private:

    class Node {
    public:
        Guest guest;
        Node* next;

        Node(const Guest& guest) : guest(guest), next(nullptr) {}
        Node() {};
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
    int getSize() const;
    Node* getHead() const {
        return head;
    };

    void sortQueue(Queue& queue);

    std::vector<Guest> getGuests() const;


    void seatGuests(std::vector<Guest>& seats, int maxSeats);



    //void splitQueue(Queue& leftQueue, Queue& rightQueue);
    //void mergeQueues(Queue& leftQueue, Queue& rightQueue);



};
