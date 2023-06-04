#include "CsvReader.h"
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<Guest> CsvReader::readGuestsFromCSV(const std::string& filename) {
    std::vector<Guest> guests;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string guestID, arrivalTime, stayDuration, isVIPString;

        std::getline(ss, guestID, ',');
        std::getline(ss, arrivalTime, ',');
        std::getline(ss, stayDuration, ',');
        std::getline(ss, isVIPString, ',');

        bool isVIP = (isVIPString == "true");

        Guest guest(guestID, arrivalTime, stayDuration, isVIP);
        guests.push_back(guest);
    }

    file.close();

    // Sort guests based on arrival time (timestamp)
    std::sort(guests.begin(), guests.end(), [](const Guest& a, const Guest& b) {
        return a.getArrivalTime() < b.getArrivalTime();
        });

    return guests;
}
