#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ClubFotbal {
private:
    string nume;
    string oras;
    int anInfiintare;
    int numarTrofee;
    vector<string> jucatori;

public:
    //constructor
    ClubFotbal() {
        nume = "No name";
        oras = "no name";
        anInfiintare = 0;
        numarTrofee = 0;
        jucatori = {};
    }

  //constr cu param
    ClubFotbal(string n, string o, int an, int trofee) {
        nume = n;
        oras = o;
        anInfiintare = an;
        numarTrofee = trofee;
        jucatori = {};
    }

   //destructor
    ~ClubFotbal() {

    }

    //met de set
    void setNume(string n) { nume = n; }
    void setOras(string o) { oras = o; }
    void setAnInfiintare(int an) { anInfiintare = an; }
    void setNumarTrofee(int t) { numarTrofee = t; }

            // met de get
    string getNume() { return nume; }
    string getOras() { return oras; }
    int getAnInfiintare() { return anInfiintare; }
    int getNumarTrofee() { return numarTrofee; }

    
   // functie adaugare jucator
    void adaugaJucator(string jucator) {
        jucatori.push_back(jucator);
    }
       
        // afiseaza jucator
    void afiseazaJucatori() {
        cout << "Jucatori in lot:" << endl;
        for (string j : jucatori) {
            cout << " - " << j << endl;
        }
    }

 //metoda care afiseaza informatiile clubului
    void afiseazaInfo() {
        cout << "Club: " << nume << endl;
        cout << "Oras: " << oras << endl;
        cout << "An infiintare: " << anInfiintare << endl;
        cout << "Numar trofee: " << numarTrofee << endl;
        afiseazaJucatori();
    }


    //metoda care calculeaza vechime club
    int calculeazaVechime(int anCurent) {
        return anCurent - anInfiintare;
    }

};

int main() {
    ClubFotbal club1;

    
    ClubFotbal club2("FCSB", "Bucuresti", 1947, 26);

    club2.adaugaJucator("Tarnovanu Stefan");
    club2.adaugaJucator("Darius Olaru");
    club2.adaugaJucator("Yuri Cissoti");


    cout << "informatii club 1:" << endl;
    club1.afiseazaInfo();

    cout << "\informatii club 2:" << endl;
   
    club2.afiseazaInfo();

    cout << "\vechimea clubului " << club2.getNume() << " este de " << club2.calculeazaVechime(2025) << " ani." << endl;

    return 0;
}