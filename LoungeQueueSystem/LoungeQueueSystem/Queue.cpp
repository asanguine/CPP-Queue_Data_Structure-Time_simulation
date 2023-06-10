#include "Queue.h"



void Queue::enqueue(const Guest& guest) {

    /*if (getSize() <= 0) {
        std::cout << "No guest left in the queue..." << std::endl;
    }*/

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
    std::cout << "\nprinting queue\n" << std::endl;
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << "Guest ID: " << temp->guest.getGuestName() << " | " << temp->guest.tellIfVIP() << std::endl;
        temp = temp->next;
    }
}



Guest Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
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
    if (head == nullptr && tail == nullptr) {
        return true;                       
    }
    else return false;
}


int Queue::getSize() const{
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}





std::vector<Guest> Queue::getGuests() const {
    std::vector<Guest> guests;
    Node* current = head;
    while (current != nullptr) {
        guests.push_back(current->guest);
        current = current->next;
    }
    return guests;
}





void Queue::mergeSort(Queue& q) {
    int n = q.getSize();
    if (n < 2) return;

    int mid = n / 2;
    Queue left;
    Queue right;

    for (int i = 0; i < mid; i++) {
        left.enqueue(q.dequeue());
    }
    for (int i = mid; i < n; i++) {
        right.enqueue(q.dequeue());
    }
    mergeSort(left);
    mergeSort(right);
    merge(left, right, q);
}


void Queue::merge(Queue& left, Queue& right, Queue& q) {

    while (!left.isEmpty() && !right.isEmpty()) {
        int leftArrival = (left.getHead()->guest.getArrivalHour()) * 60 + (left.getHead()->guest.getArrivalMinute());
        int rightArrival = (right.getHead()->guest.getArrivalHour()) * 60 + (right.getHead()->guest.getArrivalMinute());
        if (leftArrival <= rightArrival) {
            q.enqueue(left.dequeue());
        }
        else {
            q.enqueue(right.dequeue());
        }
    }

    while (!left.isEmpty()) {
        q.enqueue(left.dequeue());
    }
    while (!right.isEmpty()) {
        q.enqueue(right.dequeue());
    }
}
