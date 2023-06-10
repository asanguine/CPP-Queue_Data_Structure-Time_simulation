#include <iostream>
#include "Guest.h"
#include "Lounge.h"
#include "Queue.h"
#include "CsvReader.h"



int main()
{
	Lounge lounge(10);
	Queue queue;


	{
		Guest guest1("8Emilia Parker", "08:15", "00:10", true);
		Guest guest2("8Nathan Adams", "08:20", "00:20", false);
		Guest guest3("8Chloe Watson", "08:45", "00:20", false);
		Guest guest4("8Oscar Brooks", "08:30", "00:30", false);
		Guest guest5("8Evelyn Cooper", "08:35", "00:10", false);
		Guest guest6("8Henry Mitchell", "08:40", "00:50", true);
		Guest guest7("8Lily Turner", "08:07", "00:50", true);
		Guest guest8("8Benjamin Scott", "08:29", "00:40", false);
		Guest guest9("8Aria Walker", "08:31", "00:30", false);
		Guest guest10("8Sebastian Bennett", "08:33", "00:20", false);
		Guest guest11("9Harper Foster", "09:30", "00:30", true);
		Guest guest12("9Daniel Reed", "09:32", "00:40", false);
		Guest guest13("9Scarlett Morgan", "09:34", "00:40", false);
		Guest guest14("9Alexander Hayes", "09:36", "00:50", true);
		Guest guest15("9Mila Price", "09:38", "00:40", false);
		Guest guest16("9Carter Coleman", "09:40", "00:40", true);
		Guest guest17("9Stella Hill", "09:42", "00:40", false);
		Guest guest18("10Birkan Kurt", "10:00", "00:10", false);
		Guest guest19("9Jameson Cooper", "09:44", "00:30", true);
		Guest guest20("9Victoria Russell", "09:46", "00:50", true);
		Guest guest21("9Elijah Carter", "09:48", "00:50", false);
		
			
		queue.enqueue(guest1);
		queue.enqueue(guest2);
		queue.enqueue(guest3);
		queue.enqueue(guest4);
		queue.enqueue(guest5);
		queue.enqueue(guest6);
		queue.enqueue(guest7);
		queue.enqueue(guest8);
		queue.enqueue(guest9);
		queue.enqueue(guest10);
		queue.enqueue(guest11);
		queue.enqueue(guest12);
		queue.enqueue(guest13);
		queue.enqueue(guest14);
		queue.enqueue(guest15);
		queue.enqueue(guest16);
		queue.enqueue(guest17);
		queue.enqueue(guest18);
		queue.enqueue(guest19);
		queue.enqueue(guest20);
		queue.enqueue(guest21);
	}

	/*std::vector<Guest> guests = CsvReader::readGuestsFromCSV("guests.csv");
	for (const Guest& guest : guests) {
		queue.enqueue(guest);
	}*/

	


	queue.mergeSort(queue);
	queue.printGuests();

	
	std::cout << "\n*** seating into the lounge ***\n" << std::endl;

	lounge.seatGuests(queue);
	std::cout << lounge.getSeatsCount() << std::endl;

	lounge.printLounge();

	

	queue.printGuests();


	std::cout << "\n NOW ARE GOING TO UNSEAT GUESTS\n" << std::endl;



	while (true) {
		std::cout << "type 1 to simulate time by 5 minutes" << std::endl;
		int n;
		std::cin >> n;

		if (n == 1) {
			lounge.simulateNextTimeFrame(lounge, queue);
		}
		queue.printGuests();

	}
	
	




	return 0;
}