#include "../include/app.h"
#include <iostream>
using namespace std;

App::App() {
    cityCount = 0;
    fileHandler.loadCities("data/cities.dat", cities, cityCount);

    if (cityCount == 0) {
        cout << "  [WARNING] No cities loaded. Check data/cities.dat." << endl;
    }
}

App::~App() {
}

void App::showDivider() const {
    cout << "  ============================================" << endl;
}

void App::showWelcome() const {
    cout << endl;
    showDivider();
    cout << "   Prayer Timings & Qibla Direction App" << endl;
    cout << "            Pakistan Cities" << endl;
    showDivider();
    cout << endl;
}

void App::showProvinces(string provinces[], int provCount) const {
    showDivider();
    cout << "  Select a Province:" << endl;
    showDivider();
    for (int i = 0; i < provCount; i++) {
        cout << "    " << (i + 1) << ". " << provinces[i] << endl;
    }
    showDivider();
}

void App::showCities(City filtered[], int filteredCount) const {
    showDivider();
    cout << "  Select a City:" << endl;
    showDivider();
    for (int i = 0; i < filteredCount; i++) {
        cout << "    " << (i + 1) << ". " << filtered[i].getCityName() << endl;
    }
    showDivider();
}

void App::showResults(const City& city) const {
    cout << endl;
    showDivider();
    cout << "  City     :  " << city.getCityName() << endl;
    cout << "  Province :  " << city.getProvince()  << endl;
    showDivider();
    city.getBaseTimes().printAll();
    showDivider();
    city.showQibla();
    showDivider();
}

int App::getUniqueProvinces(string provinces[]) const {
    int provCount = 0;

    for (int i = 0; i < cityCount; i++) {
        string prov = cities[i].getProvince();
        bool found = false;

        for (int j = 0; j < provCount; j++) {
            if (provinces[j] == prov) {
                found = true;
                break;
            }
        }

        if (!found) {
            provinces[provCount] = prov;
            provCount++;
        }
    }
    return provCount;
}

int App::getCitiesForProvince(const string& province, City filtered[]) const {
    int count = 0;

    for (int i = 0; i < cityCount; i++) {
        if (cities[i].getProvince() == province) {
            filtered[count] = cities[i];
            count++;
        }
    }
    return count;
}

int App::getIntInput(int min, int max) const {
    int choice;
    cin >> choice;

    while (choice < min || choice > max) {
        cout << "  Invalid. Enter a number between " << min << " and " << max << ": ";
        cin >> choice;
    }

    return choice;
}

void App::run() {
    showWelcome();

    char again = 'Y';

    while (again == 'Y' || again == 'y') {

        string provinces[MAX_PROVINCES];
        int provCount = getUniqueProvinces(provinces);
        showProvinces(provinces, provCount);
        cout << "  Enter choice: ";
        int provChoice = getIntInput(1, provCount);

        City filtered[MAX_CITIES];
        int filteredCount = getCitiesForProvince(provinces[provChoice - 1], filtered);
        cout << endl;
        showCities(filtered, filteredCount);
        cout << "  Enter choice: ";
        int cityChoice = getIntInput(1, filteredCount);

        showResults(filtered[cityChoice - 1]);

        cout << endl;
        cout << "  Search again? (Y/N): ";
        cin >> again;
        cout << endl;
    }

    showDivider();
    cout << "  Thank you for using the Prayer Timings App." << endl;
    showDivider();
}