#pragma once
#include <string>


class Guest
{

private:

	std::string guestName;
	std::string arrivalTime;
	std::string stayDuration;
	bool isVIP;



public:
	Guest(std::string _guestName = "AAA AAA",
		  std::string _arrivalTime = "00:00",
		  std::string _stayDuration = "00:00",
		  bool _isVIP = false);

	~Guest() {};

	std::string getGuestName() const;
	int getStayDuration() const;
	std::string tellIfVIP();
	bool checkIfVIP();

	std::string getArrivalTime() const;

	int getArrivalHour() const;
	int getArrivalMinute() const;
	int getArrivalTimeinInt() const;


	int getStayDurationMinute() const;


	bool operator==(const Guest& other) const {
		return (guestName == other.guestName && arrivalTime == other.arrivalTime && stayDuration == other.stayDuration);
	}

};

