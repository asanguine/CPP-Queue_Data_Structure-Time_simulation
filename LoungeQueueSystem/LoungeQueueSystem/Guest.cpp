#include "Guest.h"
#include <iostream>


Guest::Guest(std::string _guestID,
	std::string _arrivalTime,
	std::string _stayDuration,
	bool _isVIP) :  guestID(_guestID),
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