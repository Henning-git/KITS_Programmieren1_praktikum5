#include "fahrt.h"

Fahrt::Fahrt(int n, string k, int ab, int bis): nummer(n), kunde(k), abholdatum(ab), abgabedatum(bis) {
    cout << "Fahrt erfolgreich erstellt" << endl;
}

void Fahrt::anzeigen() {
    cout << "Nr.: " << nummer
         << " Kunde " << kunde
         << " holt Fahrzeug am " << abholdatum
         << " ab und bringt es am " << abgabedatum
         << " zurück" << endl;
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

int Fahrt::getMietkosten()
{

}
