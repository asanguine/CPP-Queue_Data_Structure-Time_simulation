#pragma once
#include "Guest.h"
#include <iostream>
#include "Queue.h"
#include <vector>
#include <queue>



class Lounge
{

private:
    const int maxSeats;
    //Queue queue;
    //std::queue<Guest> remainingGuests;

    //std::string currentTime;
    //std::string currentTime;
    int currentTime;

    


public:
    Lounge(int _maxSeats = 10);

    ~Lounge() {};

    std::vector<Guest> seats;

    ///void init();

    int getSeatsCount();

    void seatGuests(Queue& queue);

    void unseatGuests(int currentTime);

    ///void checkAvailability();

    void addRemainingGuests(const Guest& guest);

    int getTimeInMinutes(const std::string& timeString);

    void printLounge();

    //void gotoNextTimeFrame();

    std::string getEarliestTime();

    std::string getNextTime(std::string arrivalTime);


    void simulateNextTimeFrame(Lounge& lounge, Queue& queue) {
  
        lounge.seatGuests(queue);
        lounge.unseatGuests(currentTime);
        currentTime += 5;
        printLounge();
     
    }

};


