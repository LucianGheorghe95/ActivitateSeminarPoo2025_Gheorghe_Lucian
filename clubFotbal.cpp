#include <iostream>
#include <string>
using namespace std;

class ClubFotbal {
private:
    string nume;
    string oras;
    int anInfiintare;
    int numarTrofee;

public:
    //constructor
    ClubFotbal() {
        nume = "No name";
        oras = "no name";
        anInfiintare = 0;
        numarTrofee = 0;
    }

  //constr cu param
    ClubFotbal(string n, string o, int an, int trofee) {
        nume = n;
        oras = o;
        anInfiintare = an;
        numarTrofee = trofee;
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

};

int main() {
    ClubFotbal club1;

    
    ClubFotbal club2("FCSB", "Bucuresti", 1947, 26);

    return 0;
}