#include "mietwagen.h"
#include <limits>

Mietwagen::Mietwagen() {
    cout << "Marke: ";
    cin >> marke;

    cout << "Kennzeichen: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> kennzeichen;

    cout << "Sitze: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> sitze;

    cout << "Tagespreis: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> tagespreis;

    cout << "Marke: " << marke << endl
         << "Kennzeichen: " << kennzeichen << endl
         << "Sitze: " << sitze << endl
         << "Tagespreis: " << fixed << setprecision(2) << tagespreis << endl;
}

void Mietwagen::anmieten(Fahrt f) {
    // Zeit überschneidet sich mit anderer Mietung
    if(!verfuegbarkeitPruefen(f)) {
        cout << "Das Auto ist zu diesem Zeitpunkt schon vermietet" << endl;
        return;
    }

    fahrtenbuch.push_back(f);
    cout << "Fahrt gespeichert" << endl;
}

void Mietwagen::fahrzeugAnzeigen() {
    cout << "Marke: " << marke << endl
         << "Kennzeichen: " << kennzeichen << endl;
}

void Mietwagen::fahrtAnzeigen(int nummer) {
    bool found = false;

    for(Fahrt fahrt: fahrtenbuch) {
        if(fahrt.getNummer() == nummer) {
            fahrt.anzeigen();
            found = true;
        }
    }

    if(!found) {
        cout << "Ungültige buchungsnummer" << endl;
    }
}

void Mietwagen::alleFahrtenAnzeigen() {
    if(fahrtenbuch.size() == 0) {
        cout << "Mietwagen wurde noch nicht verliehen." << endl;
        return;
    }

    for(Fahrt fahrt: fahrtenbuch) {
        fahrt.anzeigen();
        cout << "---------------------------------------------" << endl;
    }

}

bool Mietwagen::nummerPruefen(int nummer) {
    bool found = false;
    for(Fahrt fahrt: fahrtenbuch) {
        if(fahrt.getNummer() == nummer) {
            return true;
        }
    }

    return false;
}

bool Mietwagen::fahrtLoeschen(int nummer) {
    bool found = false;

    for(int i = 0; i < fahrtenbuch.size(); i++) {
        if(fahrtenbuch[i].getNummer() == nummer) {
            found = true;
            fahrtenbuch.erase(fahrtenbuch.begin() + i);
        }
    }

    return found;
}

int Mietwagen::berechneTage(int datum) {
    string date = to_string(datum);

    int day = stoi(date.substr(6,2));
    int month = stoi(date.substr(4,2));
    int year = stoi(date.substr(0,4));
    year = (year-2023)*365;

    int total = 0;
    static int length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i=1; i < month; i++)
        total += length[i];
    total += day;
    total += year;
    return (total);
}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f) {
    // for each fahrt in fahrtenbuch
    if(fahrtenbuch.size() == 0) {
        return true;
    }

    for(Fahrt fahrt: fahrtenbuch) {
        // neue Abgabe zwischen vorhandener Abholung und Abgabe
        if(f.getAbgabedatum() > fahrt.getAbholdatum() && f.getAbgabedatum() < fahrt.getAbgabedatum()) {
            return false;
        }
        // neue Abholung zwischen vorhandener Abholung und vorhandener Abgabe
        if(f.getAbholdatum() > fahrt.getAbholdatum() && f.getAbholdatum() < fahrt.getAbgabedatum()) {
            return false;
        }
        // vorhandene Abholung zwischen neuer Abholung und neuer Abgabe
        if(fahrt.getAbholdatum() > f.getAbholdatum() && fahrt.getAbholdatum() < f.getAbgabedatum()) {
            return false;
        }

        return true;
    }
}
