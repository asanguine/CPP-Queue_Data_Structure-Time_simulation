#pragma once
#include "Guest.h"
#include <iostream>
#include <vector>
#include <queue>

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

    ~Queue() {};


    void enqueue(const Guest& guest);
    Guest dequeue();

    Node getfront() {


    }

    bool isEmpty();
    void printGuests();
    int getSize() const;
    Node* getHead() const {
        return head;
    };

    void sortQueue(Queue& queue);


    std::vector<Guest> getGuests() const;

    void mergeSort(Queue& q);
    void merge(Queue& left, Queue& right, Queue& q);





};
