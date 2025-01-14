#ifndef AUTOVERMIETUNG_H
#define AUTOVERMIETUNG_H

#include <vector>
#include "mietwagen.h"

using namespace std;

class Autovermietung {
private:
    vector<Mietwagen *> fahrzeuge;
    bool mietwagenSuchen(int i);

public:
    Autovermietung();
    ~Autovermietung();
    void dialog();
};

#endif // AUTOVERMIETUNG_H
