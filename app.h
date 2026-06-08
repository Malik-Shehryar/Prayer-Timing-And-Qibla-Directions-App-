#ifndef APP_H
#define APP_H

#include "location.h"
#include "prayertime.h"
#include "city.h"
#include "filehandler.h"
#include <string>
using namespace std;

const int MAX_PROVINCES = 10;

class App {

private:
    City        cities[MAX_CITIES];
    int         cityCount;
    FileHandler fileHandler;

    void showWelcome()                                                const;
    void showProvinces(string provinces[], int provCount)             const;
    void showCities(City filtered[], int filteredCount)               const;
    void showResults(const City& city)                                const;
    void showDivider()                                                const;

    int getUniqueProvinces(string provinces[])                        const;
    int getCitiesForProvince(const string& province,
                             City filtered[])                         const;

    int getIntInput(int min, int max)                                 const;

public:
    App();
    ~App();
    void run();
};

#endif