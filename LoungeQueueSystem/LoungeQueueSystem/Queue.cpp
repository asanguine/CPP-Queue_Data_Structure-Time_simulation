#include "Queue.h"



void Queue::addGuest(const Guest& guest) {

    if (getSize() >= 10) {
        std::cout << "The queue is full. Cannot add more guests." << std::endl;
        remainingGuests.push_back(guest);

        return;
    }

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




void Queue::sortQueue(Queue& queue) {

    bool swapped = true;
    int size = queue.getSize();

    while (swapped) {
        swapped = false;
        Node* currentNode = queue.getHead();
        Node* nextNode = currentNode->next;

        for (int i = 0; i < size - 1; i++) {
            if (!currentNode->guest.checkIfVIP() && nextNode->guest.checkIfVIP()) {
                // Swap the VIP guest with the non-VIP guest
                Guest temp = currentNode->guest;
                currentNode->guest = nextNode->guest;
                nextNode->guest = temp;
                swapped = true;
            }

            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        size--;
    }
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


std::vector<Guest>& Queue::getRemainingGuestsArray() {
    return remainingGuests;
}

