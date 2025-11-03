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
};

int main() {


    return 0;
}