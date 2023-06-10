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


std::string Guest::getGuestName() const {
	return guestName;
}


int Guest::getStayDuration() const {
	std::string minueString = stayDuration.substr(stayDuration.find(":") + 1);
	try {
		int minute = std::stoi(minueString);
		return minute;
	}
	catch (std::exception& e) {
		std::cout << "error at stoi conversion" << std::endl;
	}
	
}


int Guest::getArrivalHour() const {
	std::string hourString = arrivalTime.substr(0, 2);
	
	try {
		return std::stoi(hourString);
	}
	catch (std::exception& e) {
		std::cout << "error at stoi conversion" << std::endl;
	}
}

int Guest::getArrivalMinute() const {
	std::string minuteString = arrivalTime.substr(3, 2);
	
	try {
		return std::stoi(minuteString);
	}
	catch (std::exception& e) {
		std::cout << "error at stoi conversion" << std::endl;
	}
}

int Guest::getArrivalTimeinInt() const {
	std::string hourString = arrivalTime.substr(0, 2);
	std::string minuteString = arrivalTime.substr(3, 2);
	
	try {
		int hour = std::stoi(hourString);
		int minute = std::stoi(minuteString);
		int time = (hour * 60) + minute;
		return time;
	}
	catch (std::exception& e) {
		std::cout << "error at stoi conversion" << std::endl;
	}
	
}

int Guest::getStayDurationMinute() const {
	std::string durationString = stayDuration.substr(3, 2);
	
	try {
		return std::stoi(durationString);
	}
	catch (std::exception& e) {
		std::cout << "error at stoi conversion" << std::endl;
	}
}