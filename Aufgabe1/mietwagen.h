#ifndef MIETWAGEN_H
#define MIETWAGEN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "fahrt.h"

using namespace std;

class Mietwagen {
private:
    string marke;
    string kennzeichen;
    int sitze;
    double tagespreis;
    vector<Fahrt> fahrtenbuch;
    bool verfuegbarkeitPruefen(Fahrt f);

public:
    Mietwagen();
    void anmieten(Fahrt f);
    void fahrzeugAnzeigen();
    void fahrtAnzeigen(int nummer);
    void alleFahrtenAnzeigen();
    bool nummerPruefen(int nummer);
    bool fahrtLoeschen(int nummer);
    int berechneTage(int datum);
};

#endif // MIETWAGEN_H
