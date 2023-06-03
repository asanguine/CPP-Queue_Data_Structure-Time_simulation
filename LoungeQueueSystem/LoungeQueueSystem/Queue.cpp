#include "Queue.h"



void Queue::addGuest(const Guest& guest) {
    Node* newNode = new Node(guest);

    if (head == nullptr) {
        head = newNode;
        tail = newNode; 
    }
    else {
        tail -> next = newNode;
        tail = newNode;
        newNode -> next = NULL;
    }
}

void Queue::printGuests() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << "Guest ID: " << temp->guest.getGuestID() << std::endl;
        temp = temp->next;
    }
}



Guest Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "\nqueue is empty\n" << std::endl;
    }

    Node* temp = head;
    Guest dequeuedGuest = temp->guest;
    head = head->next;


    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;

    return dequeuedGuest;
}



bool Queue::isEmpty() {
    if (head == tail == NULL) {
        return true;
    }
    else return false;
}


