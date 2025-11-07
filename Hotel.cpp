#include <iostream>
#include <string>
using namespace std;

class Hotel {
private:
    string numeHotel;
    string oras;
    int numarCamere;
    int camereOcupate;
    static int totalHoteluri;

public:
   //cpmstr fara parametrii
    Hotel() {
        numeHotel = "Necunoscut";
        oras = "Necunoscut";
        numarCamere = 0;
        camereOcupate = 0;
        totalHoteluri++;
    }

    // constr cu parametrii
    Hotel(string n, string o, int totalCamere, int ocupate) {
        numeHotel = n;
        oras = o;
        numarCamere = totalCamere;
        camereOcupate = ocupate;
        totalHoteluri++;
    }

    ~Hotel() {
        totalHoteluri--;
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

    void ocupaCamere(int nr) {
        if (camereOcupate + nr > numarCamere) {
            cout << "Eroare: nu sunt suficiente camere libere!\n";
        }
        else {
            camereOcupate += nr;
            cout << nr << " camere au fost ocupate.\n";
        }
    }

    void elibereazaCamere(int nr) {
        if (nr > camereOcupate) {
            cout << "Eroare: nu poti elibera mai multe camere decat sunt ocupate!\n";
        }
        else {
            camereOcupate -= nr;
            cout << nr << " camere au fost eliberate.\n";
        }
    }

    double gradOcupare() {
        if (numarCamere == 0) return 0;
        return (double)camereOcupate / numarCamere * 100;
    }

    static int getTotalHoteluri() {
        return totalHoteluri;
    }

    // afisare detalii hotel
    void afiseazaInfo() {
        cout << "hotel: " << numeHotel << endl;
        cout << "oras: " << oras << endl;
        cout << "Camere totale: " << numarCamere << endl;
        cout << "Camere ocupate: " << camereOcupate << endl;
        cout << "Camere libere: " << camereLibere() << endl;
    }

};

// ititializam variabila statica
int Hotel::totalHoteluri = 0;

int main() {

    Hotel h1("Caro", "Bucuresti", 200, 150);
    Hotel h2("Continental", "Cluj", 120, 90);

    cout << "Info hotel:" << endl;
    h1.afiseazaInfo();
    h2.afiseazaInfo();

    cout << "\nTotal hoteluri create: " << Hotel::getTotalHoteluri() << endl;

    cout << "Operatii: " << endl;
    h1.ocupaCamere(20);   
    h1.elibereazaCamere(10);
    h1.afiseazaInfo();

    cout << "Total hoteluri in sistem: " << Hotel::getTotalHoteluri() << endl;

    return 0;
}