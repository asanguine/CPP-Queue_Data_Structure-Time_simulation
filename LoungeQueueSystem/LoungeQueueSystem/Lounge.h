#pragma once
#include "Guest.h"
#include <iostream>
#include "Queue.h"
#include <vector>






class Lounge
{

private:
    const int maxSeats;
    Queue queue;
    

public:
    Lounge(int _maxSeats = 10);
    std::vector<Guest> seats;


    int getSeatsCount();
    void seatGuests();
    void unseatGuests();
    void checkAvailability();



    



};


