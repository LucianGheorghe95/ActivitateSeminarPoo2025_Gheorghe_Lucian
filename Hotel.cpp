#include <iostream>
#include <string>
using namespace std;

class Hotel {
private:
    string numeHotel;
    string oras;
    int numarCamere;
    int camereOcupate;

public:
   //cpmstr fara parametrii
    Hotel() {
        numeHotel = "Necunoscut";
        oras = "Necunoscut";
        numarCamere = 0;
        camereOcupate = 0;
    }

    // constr cu parametrii
    Hotel(string n, string o, int totalCamere, int ocupate) {
        numeHotel = n;
        oras = o;
        numarCamere = totalCamere;
        camereOcupate = ocupate;
    }

    // met de set
    void setNume(string n){ numeHotel = n; }
    void setOras(string o){ oras = o;}
    void setNumarCamere(int nr){numarCamere = nr;}
    void setCamereOcupate(int nr) {camereOcupate = nr;}

    // met de get
    string getNume(){return numeHotel;}
    string getOras() { return oras; }
    int getNumarCamere(){ return numarCamere;}
    int getCamereOcupate() {return camereOcupate; }

    // met de verificat nr camere disponibile
    int camereLibere() {
        return numarCamere - camereOcupate;
    }

};

int main() {

    Hotel h1("Caro", "Bucuresti", 200, 150);

    return 0;
}