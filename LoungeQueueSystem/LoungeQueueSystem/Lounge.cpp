#include "Lounge.h"


Lounge::Lounge(int _maxSeats) :
	maxSeats(_maxSeats) {
	seats.reserve(maxSeats);
};




void Lounge::seatGuests() {
	if (seats.size() == maxSeats) {
		std::cout << "No available seats in the lounge." << std::endl;
		return;
	}

	// Dequeue a guest from the queue
	Guest guest = queue.dequeue();

	// Seat the guest in the lounge
	seats.push_back(guest);
	std::cout << "Guest " << guest.getGuestID() << " has been seated." << std::endl;
}




int Lounge::getSeatsCount() {
	return maxSeats;
}