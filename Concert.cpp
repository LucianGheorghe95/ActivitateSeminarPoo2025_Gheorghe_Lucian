#include <iostream>
#include <string>
using namespace std;

class Concert {
private:
    string numeConcert;
    string locatie;
    string data;
    int numarSpectatori;
public:
    Concert() {
        numeConcert = "nu stiu";
        locatie = "locatie";
        data = "data";
        numarSpectatori = 0;
    }

    Concert(string nume, string loc, string d, int nr) {
        numeConcert = nume;
        locatie = loc;
        data = d;
        numarSpectatori = nr;
    }
};

int main() {

    return 0;
}