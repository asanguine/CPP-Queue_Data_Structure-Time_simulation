#pragma once
#include <string>


class Guest
{


public:
	Guest(std::string _guestID = "000",
		  std::string _arrivalTime = "00:00",
		  std::string _stayDuration = "00:00",
		  bool _isVIP = false);

	std::string getGuestID() {
		return guestID;
	}

	std::string tellIfVIP();
	bool checkIfVIP();

private:

	std::string guestID;
	std::string arrivalTime;
	std::string stayDuration;
	bool isVIP;


};

