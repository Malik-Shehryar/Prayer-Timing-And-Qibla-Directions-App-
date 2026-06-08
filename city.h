#ifndef CITY_H
#define CITY_H

#include "location.h"
#include "prayertime.h"
#include <string>
using namespace std;

class City : public Location {

private:
    PrayerTime baseTimes;
    int        zone;
    string getCardinal(double angle) const;

public:
    City();                                                  
    City(string name, string province, double qibla,
         PrayerTime baseTimes, int zone);
    ~City();

    PrayerTime getBaseTimes() const;
    int        getZone()      const;

    void showQibla() const;
 
    void showQibla(double angle) const;

    void   display() const override;
    string getInfo() const override;
};

#endif