#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "city.h"

const int MAX_CITIES = 50;

class FileHandler {

public:
    void loadCities(const string& filename, City cities[], int& cityCount);
};

#endif