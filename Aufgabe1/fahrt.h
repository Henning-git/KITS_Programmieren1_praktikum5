#ifndef FAHRT_H
#define FAHRT_H

#include <string>
#include <iostream>

using namespace std;

class Fahrt {
private:
    int nummer;
    string kunde;
    int abholdatum;
    int abgabedatum;
    int mietkosten;

public:
    Fahrt(int n, string k, int ab, int bis);
    void anzeigen();
    int getNummer();
    int getAbholdatum();
    int getAbgabedatum();
    int getMietkosten();
};

#endif // FAHRT_H
