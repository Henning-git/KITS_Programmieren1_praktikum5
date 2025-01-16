#ifndef FAHRT_H
#define FAHRT_H

#include <string>

using namespace std;

class Fahrt {
private:
    int nummer;
    string kunde;
    int abholdatum;
    int abgabedatum;
    double mietkosten;

public:
    Fahrt(int n, string k, int ab, int bis);
    void anzeigen();
    int getNummer();
    int getAbholdatum();
    int getAbgabedatum();
    double getMietkosten();
    void setMietkosten(double mietkosten);
};

#endif // FAHRT_H
