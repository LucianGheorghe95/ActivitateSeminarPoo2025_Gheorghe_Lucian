#include <iostream>
#include <string>
using namespace std;

class Concert {
private:
    string numeConcert;
    string locatie;
    string data;
    int numarSpectatori;
    double pretBilet;   
    int durataOre;
public:
    Concert() {
        numeConcert = "nu stiu";
        locatie = "locatie";
        data = "data";
        numarSpectatori = 0;
        pretBilet = 0.0;
        int durataOre = 0;
    }

    Concert(string nume, string loc, string d, int nr, double pret, int durata) {
        numeConcert = nume;
        locatie = loc;
        data = d;
        numarSpectatori = nr;
        pretBilet = pret;
        durataOre = durata;
    }

    double venitTotal() const {
        return numarSpectatori * pretBilet;
    }

    void reducePretBilet(double procent) {
        if (procent < 0 || procent > 100) {
            cout << "Procent invalid!" << endl;
            return;
        }
        pretBilet = pretBilet - (pretBilet * procent / 100);
    }

    bool esteBiletScump() const {
        return pretBilet > 300;
    }

    void afiseazaInfo() const {
        cout << "Concert: " << numeConcert << endl;
        cout << "Locatie: " << locatie << endl;
        cout << "Data: " << data << endl;
        cout << "Numar spectatori: " << numarSpectatori << endl;
        cout << "Pret bilet: " << pretBilet << " lei" << endl;
        cout << "Durata: " << durataOre << " ore" << endl;
        cout << "Venit total estimat: " << venitTotal() << " lei" << endl; 
    }

    bool esteSoldOut() const {
        if (numarSpectatori > 50000) {
            return true;
        }
        return false;
    }

    bool esteSuperConcert() const {
        if (venitTotal() > 10000000) {
            return true;
        }
        return false;
    }

};

int main() {

    Concert c1;
    cout << "Concert implicit" << endl;
    c1.afiseazaInfo();

    Concert c2("Untold", "Cluj", "04.08.2025", 75000, 350.5, 6);
    cout << "\nConcert 2:" << endl;
    c2.afiseazaInfo();

    cout << "\nconcert 2 bilet scump?: " << (c2.esteBiletScump() ? "DA" : "NU") << endl;

    cout << "\nconcert 1  este sold out?: " << (c1.esteSoldOut() ? "DA" : "NU") << endl;
    cout << "concert 2  e sold out?: " << (c2.esteSoldOut() ? "DA" : "NU") << endl;

    cout << "\nconcert 1 e super concert?: " << (c1.esteSuperConcert() ? "da" : "nu") << endl; 
    cout << "concert 2 e super concert?: " << (c2.esteSuperConcert() ? "da" : "NU") << endl; 

    c2.reducePretBilet(20);
    c2.afiseazaInfo();

    cout << "\ndupa reducere, bilet scump?: " << (c2.esteBiletScump() ? "DA" : "NU") << endl;



    return 0;
}