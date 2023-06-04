#include "Guest.h"
#include <iostream>


Guest::Guest(std::string _guestName,
	std::string _arrivalTime,
	std::string _stayDuration,
	bool _isVIP) :  guestName(_guestName),
					arrivalTime(_arrivalTime),
					stayDuration(_stayDuration),
					isVIP(_isVIP){}


std::string Guest::tellIfVIP() {
	std::string VIPstatus;
	if (isVIP) {
		VIPstatus = "VIP";
	}
	else {
		VIPstatus = "non-VIP";
	}
	return VIPstatus;
}

bool Guest::checkIfVIP() {
	if (isVIP) return true;
	else return false;
}


std::string Guest::getArrivalTime() const {
	return arrivalTime;
}



