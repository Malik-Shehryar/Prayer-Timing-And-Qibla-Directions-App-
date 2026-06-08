#include "../include/filehandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


void FileHandler::loadCities(const string& filename, City cities[], int& cityCount) {
    cityCount = 0;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "  [ERROR] Could not open " << filename << endl;
        cout << "  Make sure cities.dat is inside the data/ folder." << endl;
        return;
    }

    string line;
    while (getline(file, line) && cityCount < MAX_CITIES) {

        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string token;

        string cityName, province, fajr, dhuhr, asr, maghrib, isha;
        double qiblaAngle;
        int zone;

        getline(ss, cityName,   '|');
        getline(ss, province,   '|');

        getline(ss, token, '|');
        qiblaAngle = stod(token);

        getline(ss, token, '|');
        zone = stoi(token);

        getline(ss, fajr,    '|');
        getline(ss, dhuhr,   '|');
        getline(ss, asr,     '|');
        getline(ss, maghrib, '|');
        getline(ss, isha,    '|');

        PrayerTime baseTimes(fajr, dhuhr, asr, maghrib, isha);
        cities[cityCount] = City(cityName, province, qiblaAngle, baseTimes, zone);
        cityCount++;
    }

    file.close();
}