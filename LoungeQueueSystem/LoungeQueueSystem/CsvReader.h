#pragma once
#include <string>
#include <vector>
#include "Guest.h"




class CsvReader {
public:
    static std::vector<Guest> readGuestsFromCSV(const std::string& filename);

};