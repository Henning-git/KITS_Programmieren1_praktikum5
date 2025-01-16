#include "fahrt.h"
#include <iostream>
#include <iomanip>

Fahrt::Fahrt(int n, string k, int ab, int bis): nummer(n), kunde(k), abholdatum(ab), abgabedatum(bis) {
    cout << "Fahrt erfolgreich erstellt" << endl;
}

void Fahrt::anzeigen() {
    cout << "Nr.: " << nummer
         << " Kunde " << kunde
         << " holt Fahrzeug am " << abholdatum
         << " ab und bringt es am " << abgabedatum
         << " zurück"
         << " Preis: " << fixed << setprecision(2) << this->mietkosten << endl;
}

int Fahrt::getNummer() {
    return nummer;
}

int Fahrt::getAbholdatum() {
    return abholdatum;
}

int Fahrt::getAbgabedatum() {
    return abgabedatum;
}

double Fahrt::getMietkosten() {
    return mietkosten;
}

void Fahrt::setMietkosten(double mietkosten) {
    this->mietkosten = mietkosten;
}


