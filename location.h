#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location {

private:
    string cityName;
    string province;
    double qiblaAngle;

public:
    Location();                                         
    Location(string name, string province, double qibla);
    virtual ~Location();

    string getCityName()   const;
    string getProvince()   const;
    double getQiblaAngle() const;

    virtual void   display() const = 0;
    virtual string getInfo() const = 0;
};

#endif