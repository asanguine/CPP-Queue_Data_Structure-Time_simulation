#pragma once
#include <string>


class Guest
{


public:
	Guest(std::string _guestName = "AAA AAA",
		  std::string _arrivalTime = "00:00",
		  std::string _stayDuration = "00:00",
		  bool _isVIP = false);

	std::string getGuestName() const {
		return guestName;
	}

	std::string tellIfVIP();
	bool checkIfVIP();

	std::string getArrivalTime() const;

private:

	std::string guestName;
	std::string arrivalTime;
	std::string stayDuration;
	bool isVIP;


};

