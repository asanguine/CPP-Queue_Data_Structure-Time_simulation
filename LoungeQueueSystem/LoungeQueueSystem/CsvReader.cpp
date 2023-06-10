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
        std::string guestName, arrivalTime, stayDuration, isVIPString;

        std::getline(ss, guestName, ',');
        std::getline(ss, arrivalTime, ',');
        std::getline(ss, stayDuration, ',');
        std::getline(ss, isVIPString, ',');

        bool isVIP = (isVIPString == "true");

        Guest guest(guestName, arrivalTime, stayDuration, isVIP);
        guests.push_back(guest);
    }

    file.close();
    return guests;
}
