#include "../include/location.h"

Location::Location()
    : cityName(""), province(""), qiblaAngle(0.0) {
}

Location::Location(string name, string province, double qibla)
    : cityName(name), province(province), qiblaAngle(qibla) {
}

Location::~Location() {
}

string Location::getCityName() const {
    return cityName;
}

string Location::getProvince() const {
    return province;
}

double Location::getQiblaAngle() const {
    return qiblaAngle;
}