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
        std::cout << "Guest ID: " << temp->guest.getGuestID() << " | " << temp->guest.tellIfVIP() << std::endl;
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





