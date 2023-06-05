#include <iostream>
#include "Guest.h"
#include "Lounge.h"
#include "Queue.h"
#include "CsvReader.h"



int main()
{
	Lounge lounge(10);
	Queue queue;
	//std::vector<Guest> seats;

	{
		Guest guest1("Emilia Parker", "08:15", "00:32", true);
		Guest guest2("Nathan Adams", "08:20", "00:48", false);
		Guest guest3("Chloe Watson", "08:25", "00:22", false);
		Guest guest4("Oscar Brooks", "08:30", "00:39", false);
		Guest guest5("Evelyn Cooper", "08:35", "00:45", false);
		Guest guest6("Henry Mitchell", "08:40", "00:50", true);
		Guest guest7("Lily Turner", "08:27", "00:59", true);
		Guest guest8("Benjamin Scott", "08:29", "02:47", false);
		Guest guest9("Aria Walker", "08:31", "01:36", false);
		Guest guest10("Sebastian Bennett", "08:33", "00:28", false);
		Guest guest11("Harper Foster", "09:30", "00:36", true);
		Guest guest12("Daniel Reed", "09:32", "00:46", false);
		Guest guest13("Scarlett Morgan", "09:34", "00:40", false);
		Guest guest14("Alexander Hayes", "09:36", "00:50", true);
		Guest guest15("Mila Price", "09:38", "00:45", false);
		Guest guest16("Carter Coleman", "09:40", "00:48", true);
		Guest guest17("Stella Hill", "09:42", "00:49", false);
		Guest guest18("Jameson Cooper", "09:44", "00:38", true);
		Guest guest19("Victoria Russell", "09:46", "00:52", true);
		Guest guest20("Elijah Carter", "09:48", "00:57", false);
			
		queue.addGuest(guest1);
		queue.addGuest(guest2);
		queue.addGuest(guest3);
		queue.addGuest(guest4);
		queue.addGuest(guest5);
		queue.addGuest(guest6);
		queue.addGuest(guest7);
		queue.addGuest(guest8);
		queue.addGuest(guest9);
		queue.addGuest(guest10);
		queue.addGuest(guest11);
		queue.addGuest(guest12);
		queue.addGuest(guest13);
		queue.addGuest(guest14);
		queue.addGuest(guest15);
		queue.addGuest(guest16);
		queue.addGuest(guest17);
		queue.addGuest(guest18);
		queue.addGuest(guest19);
		queue.addGuest(guest20);
	}

	/*std::vector<Guest> guests = CsvReader::readGuestsFromCSV("guests.csv");
	for (const Guest& guest : guests) {
		queue.addGuest(guest);
	}*/

	

	std::cout << "\n**** unsorted arrival to the queue ******\n" << std::endl;

	queue.printGuests();


	std::cout << "\n**** sorted in the queue ****\n" << std::endl;

	queue.sortQueue(queue);
	queue.printGuests();


	std::cout << "\n*** seating into the lounge ***\n" << std::endl;

	lounge.seatGuests(queue);
	std::cout << lounge.getSeatsCount() << std::endl;

	lounge.printLounge();

	std::cout << "\n*** new queue ***\n" << std::endl;

	///queue.sortQueue(queue);
	///queue.printGuests();

	/*std::cout << "\nprinting lounge...\n" << std::endl;
	for (Guest& guest : seats) {
		std::cout << guest.getGuestName() << " | " << guest.tellIfVIP() << std::endl;
	}*/

	

	//lounge.gotoNextTimeFrame();



	return 0;
}