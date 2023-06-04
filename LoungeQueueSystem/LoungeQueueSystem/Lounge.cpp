#include "Lounge.h"


Lounge::Lounge(int _maxSeats) :
	maxSeats(_maxSeats) {
	//seats.reserve(maxSeats);
};




int Lounge::getSeatsCount() {
	return maxSeats;
}


//void Lounge::printLounge() {
//	std::cout << "\nprinting lounge...\n" << std::endl;
//
//
//	for (Guest& guest : seats) {
//		std::cout << guest.getGuestName() << " | " << guest.tellIfVIP() << std::endl;
//	}
//
//}


void Lounge::unseatGuests() {


}
