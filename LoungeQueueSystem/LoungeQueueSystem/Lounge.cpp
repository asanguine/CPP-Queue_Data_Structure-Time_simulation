#include "Lounge.h"



/// INIT ?????
//void Lounge::init() {
//	//currentTime = getEarliestTime(seats);
//}

Lounge::Lounge(int _maxSeats) :
	maxSeats(_maxSeats) {
	currentTime = 8 * 60;
	//seats.reserve(maxSeats);
};




int Lounge::getSeatsCount() {
	return maxSeats;
}


void Lounge::printLounge() {
	std::cout << "\nprinting lounge...\n" << std::endl;


	for (Guest& guest : seats) {
		std::cout << guest.getGuestName() << " | " << guest.tellIfVIP() << std::endl;
	}

}



void Lounge::seatGuests(Queue& queue) {
	int availableSeats = maxSeats - seats.size();
	std::cout << "available seats: " << availableSeats << std::endl;
	if (seats.size() == maxSeats) {
		std::cout << "No available seats in the lounge." << std::endl;
		return;
	}
	else std::cout << "there is space " << availableSeats << std::endl;


	// Seat guests from the queue until no seats are available
	while (availableSeats > 0 && queue.getSize() > 0) { //
		std::cout << " starting to seat " << std::endl;
		Guest guest = queue.dequeue();
		seats.push_back(guest);
		availableSeats--;
		std::cout << "seats : " << availableSeats << std::endl;
		std::cout << guest.getGuestName() << " has been seated." << std::endl;
	}

	

	if (queue.isEmpty()) {
		std::vector<Guest>& remainingGuests = queue.getRemainingGuestsArray();
		int numRemainingGuests = remainingGuests.size();

		for (int i = 0; i < std::min(numRemainingGuests, 10); i++) {
			queue.addGuest(remainingGuests[i]);
		}
	}


	// If there are still available seats, fill the queue with the remaining guests
	/*if (availableSeats > 0) {
		while (availableSeats > 0 && !remainingGuests.empty()) {
			Guest guest = remainingGuests.front();
			remainingGuests.pop();
			queue.addGuest(guest);
			availableSeats--;
			std::cout << guest.getGuestName() << " has joined the queue." << std::endl;
		}
	}*/
}



int Lounge::getTimeInMinutes(const std::string& timeString) {
	size_t colonPos = timeString.find(":");
	if (colonPos != std::string::npos) {
		std::string minutesString = timeString.substr(colonPos + 1);
		return std::stoi(minutesString);
	}
	return 0;
}





void Lounge::unseatGuests(int currentTime) {
	std::cout << currentTime <<std::endl;
	std::vector<Guest> guestsToUnseat;
	int currentMinute = currentTime % 60;
	int currentHour = currentTime / 60; // Starting hour is 8:00 AM
	std::cout << currentMinute << std::endl;
	std::cout << currentHour << std::endl;
	for (Guest& g : seats) {
		int arrivalMinute = g.getArrivalMinute();
		int arrivalHour = g.getArrivalHour();

		int elapsedMinutes = (currentHour - arrivalHour) * 60 + (currentMinute - arrivalMinute);

		if (elapsedMinutes >= g.getStayDuration()) {
			guestsToUnseat.push_back(g);
			std::cout << g.getGuestName() << " has been unseated." << std::endl;
		}
	}

	// Remove unseated guests from the seats vector
	for (const Guest& guest : guestsToUnseat) {
		seats.erase(std::remove(seats.begin(), seats.end(), guest), seats.end());
	}
	std::cout << currentTime << std::endl;
}





//void Lounge::gotoNextTimeFrame() {
//	std::string earliestArrivalTime = seats.empty() ? "00:00" : seats[0].getArrivalTime();
//	std::cout << "starting time: " << earliestArrivalTime << std::endl;
//	
//
//	currentTime = getNextTime(currentTime);
//}



std::string Lounge::getEarliestTime() {
	return seats[0].getArrivalTime();
}



std::string Lounge::getNextTime(std::string arrivalTime) {
	std::string next_timestamp = "";

	for (Guest& g : seats) {
		if (g.getArrivalTime() > arrivalTime) {
			next_timestamp = g.getArrivalTime();
			break;
		}
	}
	if (next_timestamp == "") {
		next_timestamp = seats[0].getArrivalTime(); // if there is no timestamp left, go back to start
	}

	return next_timestamp;
}




//void Lounge::addRemainingGuests(const Guest& guest) {
//	remainingGuests.push(guest);
//}