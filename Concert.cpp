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

    void afiseazaInfo() const {
        cout << "Concert: " << numeConcert << endl;
        cout << "Locatie: " << locatie << endl;
        cout << "Data: " << data << endl;
        cout << "Numar spectatori: " << numarSpectatori << endl;
    }
};

int main() {

    Concert c1;
    cout << "Concert implicit" << endl;
    c1.afiseazaInfo();

    Concert c2("Untold", "Cluj", "04.08.2025", 75000);
    cout << "\nConcert 2:" << endl;
    c2.afiseazaInfo();

    return 0;
}