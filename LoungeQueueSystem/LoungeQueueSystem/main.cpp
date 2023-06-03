#include <iostream>
#include "Guest.h"
#include "Lounge.h"
#include "Queue.h"



int main()
{
	Lounge lounge(10);

	Guest guest1("000", "00:00", "00:00", false);
	Guest guest2("001", "00:00", "00:00", false);
	Guest guest3("002", "00:00", "00:00", false);
	Guest guest4("003", "00:00", "00:00", false);

	Queue queue;

	queue.addGuest(guest1);
	queue.addGuest(guest2);
	queue.addGuest(guest3);
	queue.addGuest(guest4);

	queue.printGuests();










	return 0;
}
