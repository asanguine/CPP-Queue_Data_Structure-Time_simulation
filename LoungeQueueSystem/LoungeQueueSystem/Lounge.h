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
    int currentTime;

    

public:
    Lounge(int _maxSeats = 10);

    ~Lounge() {};

    std::vector<Guest> seats;

    int getSeatsCount();

    void seatGuests(Queue& queue, int currentTime);

    void unseatGuests(int currentTime);

    int getCurrentTime()const;

    void addRemainingGuests(const Guest& guest);

    int getTimeInMinutes(const std::string& timeString);

    void printLounge();

    void simulateNextTimeFrame(Lounge& lounge, Queue& queue);

};