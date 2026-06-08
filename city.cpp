#include "../include/city.h"
#include <iostream>
#include <iomanip>
using namespace std;


City::City()
    : Location(), baseTimes(), zone(0) {
}


City::City(string name, string province, double qibla,
           PrayerTime baseTimes, int zone)
    : Location(name, province, qibla),
      baseTimes(baseTimes),
      zone(zone) {
}


City::~City() {
}


PrayerTime City::getBaseTimes() const {
    return baseTimes;
}

int City::getZone() const {
    return zone;
}


string City::getCardinal(double angle) const {
    if (angle <  22.5)  return "N";
    if (angle <  67.5)  return "NE";
    if (angle < 112.5)  return "E";
    if (angle < 157.5)  return "SE";
    if (angle < 202.5)  return "S";
    if (angle < 247.5)  return "SW";
    if (angle < 292.5)  return "W";
    if (angle < 337.5)  return "NW";
    return "N";
}


void City::showQibla() const {
    cout << "  Qibla Direction :  " << fixed << setprecision(1)
         << getQiblaAngle() << " degrees from North" << endl;
    cout << "  Compass         :  " << getCardinal(getQiblaAngle()) << endl;
}


void City::showQibla(double angle) const {
    cout << "  Qibla Direction :  " << fixed << setprecision(1)
         << angle << " degrees from North" << endl;
    cout << "  Compass         :  " << getCardinal(angle) << endl;
}


void City::display() const {
    cout << "  City     :  " << getCityName() << endl;
    cout << "  Province :  " << getProvince() << endl;
    cout << "  Zone     :  " << zone          << endl;
}


string City::getInfo() const {
    return getCityName() + " (" + getProvince() + ")";
}