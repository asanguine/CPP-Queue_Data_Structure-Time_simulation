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

	int getArrivalHour() const {
		std::string hourString = arrivalTime.substr(0, 2);
		return std::stoi(hourString);
	}

	int getArrivalMinute() const {
		std::string minuteString = arrivalTime.substr(3, 2);
		return std::stoi(minuteString);
	}

	int getStayDurationMinute() const {
		std::string durationString = stayDuration.substr(3, 2);
		return std::stoi(durationString);
	}


	bool operator==(const Guest& other) const {
		return (guestName == other.guestName && arrivalTime == other.arrivalTime && stayDuration == other.stayDuration);
	}

};

