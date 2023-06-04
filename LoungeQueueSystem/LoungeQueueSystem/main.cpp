#include <iostream>
#include "Guest.h"
#include "Lounge.h"
#include "Queue.h"
#include "CsvReader.h"



int main()
{
	Lounge lounge(10);

	Guest guest1("000", "00:00", "00:00", false);
	Guest guest2("001", "00:00", "00:00", false);
	Guest guest3("002", "00:00", "00:00", true);
	Guest guest4("003", "00:00", "00:00", false);
	Guest guest5("004", "00:00", "00:00", true);
	Guest guest6("005", "00:00", "00:00", false);

	Queue queue;

	queue.addGuest(guest1);
	queue.addGuest(guest2);
	queue.addGuest(guest3);
	queue.addGuest(guest4);
	queue.addGuest(guest5);
	queue.addGuest(guest6);


	/*std::vector<Guest> guests = CsvReader::readGuestsFromCSV("guests.csv");
	for (const Guest& guest : guests) {
		queue.addGuest(guest);
	}*/

	std::vector<Guest> seats;

	std::cout << "\n*********************\n" << std::endl;

	queue.printGuests();

	queue.sortQueue(queue);

	std::cout << "\n*********************\n" << std::endl;

	queue.printGuests();

	std::cout << "\n*********************\n" << std::endl;

	

	queue.seatGuests(seats, lounge.getSeatsCount());

	std::cout << "\n*********************\n" << std::endl;

	std::cout << lounge.getSeatsCount() << std::endl;




	std::cout << "\nprinting lounge...\n" << std::endl;
	for (Guest& guest : seats) {
		std::cout << guest.getGuestName() << " | " << guest.tellIfVIP() << std::endl;
	}





	return 0;
}