#include "autovermietung.h"
#include <limits>

bool Autovermietung::mietwagenSuchen(int i) {
    if(i > fahrzeuge.size() - 1) {
        return false;
    }
    return true;
}

Autovermietung::Autovermietung() {}

Autovermietung::~Autovermietung() {
    for(Mietwagen* fahrzeug: fahrzeuge) {
        delete fahrzeug;
    }
    cout << "Hasta la vista!" << endl;
}

void Autovermietung::dialog() {
    // Variablen deklarieren
    Mietwagen* mietwagen;

    // dynamische Erstellung eines Mietwagens und in Vector schreiben
    mietwagen = new Mietwagen();
    fahrzeuge.push_back(mietwagen);

    while (true) {
        cout << "1: Fahrzeug mieten" << endl;
        cout << "2: Fahrt anzeigen" << endl;
        cout << "3: Alle Fahrten anzeigen" << endl;
        cout << "4: Fahrt löschen" << endl;
        cout << "5: Fahrzeug hinzufügen" << endl;
        cout << "6: Alle Fahrzeuge ausgeben" << endl;
        cout << "7: umsatzliste" << endl;
        cout << "0: Programm beenden" << endl;

        char eingabe;
        cin >> eingabe;

        switch(eingabe){
        case '1': {         // Fahrzeug mieten
            int i;
            cout << "Fahrzeugnummer: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> i;
            if(!mietwagenSuchen(i)) {
                cout << "Das Auto existiert nicht" << endl;
                break;
            }
            mietwagen = fahrzeuge[i];
            mietwagen->fahrzeugAnzeigen();

            int buchungsnummer;
            cout << "Fahrzeug mieten: " << endl
                 << "Buchungsnummer: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> buchungsnummer;

            // does buchungsnummer already exist
            if(mietwagen->nummerPruefen(buchungsnummer)) {
                cout << "Die Buchungsnummer existiert bereits" << endl;
                break;
            }

            string kunde;
            cout << "Kunde: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> kunde;

            int abholdatum;
            cout << "Abholdatum: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> abholdatum;

            int abgabedatum;
            cout << "Abgabedatum: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> abgabedatum;

            // abholdatum nach abgabedatum
            if(abholdatum > abgabedatum) {
                cout << "Abholung muss vor Abgabe sein" << endl;
                break;
            }

            Fahrt fahrt = Fahrt(buchungsnummer, kunde, abholdatum, abgabedatum);
            mietwagen->anmieten(fahrt);
        }
        break;

        case '2': {         // Fahrt anzeigen
            int i;
            cout << "Fahrzeugnummer: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> i;
            if(!mietwagenSuchen(i)) {
                cout << "Das Auto existiert nicht" << endl;
                break;
            }
            mietwagen = fahrzeuge[i];
            mietwagen->fahrzeugAnzeigen();

            int buchungsnummer;
            cout << "Welche Buchungsnummer möchtest du abfragen: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> buchungsnummer;

            mietwagen->fahrtAnzeigen(buchungsnummer);
        }
        break;

        case '3': {         // Alle Fahrten anzeigen
            int i;
            cout << "Fahrzeugnummer: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> i;
            if(!mietwagenSuchen(i)) {
                cout << "Das Auto existiert nicht" << endl;
                break;
            }
            mietwagen = fahrzeuge[i];
            mietwagen->fahrzeugAnzeigen();

            mietwagen->alleFahrtenAnzeigen();
        }
        break;

        case '4': {         // Fahrt Löschen
            int i;
            cout << "Fahrzeugnummer: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> i;
            if(!mietwagenSuchen(i)) {
                cout << "Das Auto existiert nicht" << endl;
                break;
            }
            mietwagen = fahrzeuge[i];
            mietwagen->fahrzeugAnzeigen();

            int buchungsnummer;
            cout << "Welche Buchungsnummer möchtest du löschen: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> buchungsnummer;

            if(mietwagen->fahrtLoeschen(buchungsnummer)) {
                cout << "Fahrt erfolgreich gelöscht." << endl;
            }
            else {
                cout << "Ungültige Buchungsnummer" << endl;
            }
        }
        break;

        case '5': {         // Fahrzeug hinzufügen
            // dynamische Erstellung eines Mietwagens und in Vector schreiben
            mietwagen = new Mietwagen();
            fahrzeuge.push_back(mietwagen);
        }
        break;

        case '6': {         // Alle Fahrzeuge ausgeben
            for(int i = 0; i < fahrzeuge.size(); i++) {
                fahrzeuge[i]->fahrzeugAnzeigen();
                fahrzeuge[i]->alleFahrtenAnzeigen();
            }
        }
        break;

        case '7': {         // Umsatzliste
            double umsatz = 0;
            for(Mietwagen* fahrzeug: fahrzeuge) {
                umsatz += fahrzeug->printUmsatz();
            }
            cout << "Unternehmensumsatz: " << umsatz << endl;
        }
        break;

        case '0':{         // Programm beenden
            return;
            break;
        }
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}
