#ifndef PRAYERTIME_H
#define PRAYERTIME_H

#include <string>
using namespace std;


class PrayerTime {

private:
    string fajr;
    string dhuhr;
    string asr;
    string maghrib;
    string isha;

public:
    PrayerTime();
    PrayerTime(string fajr, string dhuhr, string asr,
               string maghrib, string isha);

    string getFajr()    const;
    string getDhuhr()   const;
    string getAsr()     const;
    string getMaghrib() const;
    string getIsha()    const;

    void printAll() const;
};

#endif