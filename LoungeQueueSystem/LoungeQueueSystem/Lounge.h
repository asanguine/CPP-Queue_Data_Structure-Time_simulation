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
    std::queue<Guest> remainingGuests;


    //std::string currentTime;
    std::string currentTime;

    


public:
    Lounge(int _maxSeats = 10);

    std::vector<Guest> seats;

    ///void init();

    int getSeatsCount();

    void seatGuests(Queue& queue);

    void unseatGuests();

    ///void checkAvailability();

    void addRemainingGuests(const Guest& guest);



    void printLounge();

    void gotoNextTimeFrame();

    std::string getEarliestTime();

    std::string getNextTime(std::string arrivalTime);


};


