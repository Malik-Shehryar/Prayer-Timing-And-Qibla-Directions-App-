#include "../include/prayertime.h"
#include <iostream>
using namespace std;


PrayerTime::PrayerTime()
    : fajr("00:00"), dhuhr("00:00"), asr("00:00"),
      maghrib("00:00"), isha("00:00") {
}

PrayerTime::PrayerTime(string fajr, string dhuhr, string asr,
                       string maghrib, string isha)
    : fajr(fajr), dhuhr(dhuhr), asr(asr),
      maghrib(maghrib), isha(isha) {
}


string PrayerTime::getFajr()    const { return fajr;    }
string PrayerTime::getDhuhr()   const { return dhuhr;   }
string PrayerTime::getAsr()     const { return asr;     }
string PrayerTime::getMaghrib() const { return maghrib; }
string PrayerTime::getIsha()    const { return isha;    }


void PrayerTime::printAll() const {
    cout << "  Fajr    :  " << fajr    << endl;
    cout << "  Dhuhr   :  " << dhuhr   << endl;
    cout << "  Asr     :  " << asr     << endl;
    cout << "  Maghrib :  " << maghrib << endl;
    cout << "  Isha    :  " << isha    << endl;
}