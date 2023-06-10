#include <iostream>
#include "Guest.h"
#include "Lounge.h"
#include "Queue.h"
#include "CsvReader.h"
#include <chrono>
#include <thread> 



int main()
{
	Lounge lounge(10);
	Queue queue;
	int currentTime = 480;


	std::vector<Guest> guests = CsvReader::readGuestsFromCSV("guests.csv");
	for (const Guest& guest : guests) {
		queue.enqueue(guest);
	}



	queue.mergeSort(queue);
	queue.printGuests();

	
	std::cout << "\n*** seating into the lounge ***\n" << std::endl;

	lounge.seatGuests(queue, currentTime);
	std::cout << lounge.getSeatsCount() << std::endl;

	lounge.printLounge();

	
	//queue.printGuests();


	std::cout << "\n NOW ARE GOING TO UNSEAT GUESTS\n" << std::endl;


	/*
	while (true) {
		std::cout << "type 1 to simulate time by 5 minutes" << std::endl;
		int n;
		std::cin >> n;

		if (n == 1) {
			lounge.simulateNextTimeFrame(lounge, queue);
		}
		//queue.printGuests();
	}*/
	
	while (lounge.getCurrentTime() <= 720) {

		lounge.simulateNextTimeFrame(lounge, queue);

		std::this_thread::sleep_for(std::chrono::seconds(1));  // Pause for 2 seconds before the next time frame
		
	}
	
	
	std::cout << "***********\nit is 12:00, the lounge is closed!\n***********\n\n\n";
	
	return 0;
}