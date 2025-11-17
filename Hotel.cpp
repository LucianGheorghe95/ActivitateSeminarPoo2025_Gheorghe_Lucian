#include <iostream>
#include <string>
#include <vector> 
using namespace std;

class Client {
private:
    string nume;
    int varsta;
    int numarCamera;
    int zileSejur;
public:
    Client() : nume("N/A"), varsta(0), numarCamera(-1), zileSejur(0) {}
    Client(string n, int v, int camera, int zile) : nume(n), varsta(v), numarCamera(camera), zileSejur(zile) {}

    void setNume(string n) { nume = n; }
    void setVarsta(int v) { varsta = v; }
    void setNumarCamera(int c) { numarCamera = c; }
    void setZileSejur(int z) { zileSejur = z; }

    string getNume() const { return nume; }
    int getVarsta() const { return varsta; }
    int getNumarCamera() const { return numarCamera; }
    int getZileSejur() const { return zileSejur; } 

    void afiseaza() const {
        cout << "Client: " << nume
            << ", varsta: " << varsta
            << ", camera: " << numarCamera
            << ", zile sejur: " << zileSejur << "\n";
    }
};


class Hotel {
private:
    string numeHotel;
    string oras;
    int numarCamere;
    int camereOcupate;
    static int totalHoteluri;

    vector<Client> clienti; 

    bool esteCameraLibera(int nr) const { 
        if (nr < 1 || nr > numarCamere) return false;
        for (const auto& c : clienti) {
            if (c.getNumarCamera() == nr) return false;
        }
        return true;
    }

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
    string getNume() const {return numeHotel;}
    string getOras() const { return oras; }
    int getNumarCamere() const { return numarCamere;}
    //int getCamereOcupate() {return camereOcupate; }

    // met de verificat nr camere disponibile
    int camereLibere() const {
        return numarCamere - (int)clienti.size();
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

    double gradOcupare() const {
        if (numarCamere == 0) return 0;
        return (double)clienti.size() / numarCamere * 100.0;
    }

    static int getTotalHoteluri() {
        return totalHoteluri;
    }

    // afisare detalii hotel
    void afiseazaInfo() const {
        cout << "\nHotel: " << numeHotel << "\n"
            << "Oras: " << oras << "\n"
            << "Camere totale: " << numarCamere << "\n"
            << "Rezervari active: " << clienti.size() << "\n"
            << "Camere libere: " << camereLibere() << "\n"
            << "Grad de ocupare: " << gradOcupare() << "%\n";
    }

    bool rezervaCamera(string numeClient, int varsta, int nrCamera, int zileSejur) {
        if (nrCamera < 1 || nrCamera > numarCamere) {
            cout << "Eroare: camera " << nrCamera << " nu exista.\n";
            return false;
        }
        if (!esteCameraLibera(nrCamera)) {
            cout << "Eroare: camera " << nrCamera << " este deja ocupata.\n";
            return false;
        }
        clienti.emplace_back(numeClient, varsta, nrCamera, zileSejur);
        cout << "Rezervare reusita pentru " << numeClient << " la camera " << nrCamera << ".\n";
        return true;
    }

    bool anuleazaRezervareCamera(int nrCamera) {
        for (size_t i = 0; i < clienti.size(); ++i) {
            if (clienti[i].getNumarCamera() == nrCamera) {
                cout << "Rezervarea pentru camera " << nrCamera
                    << " (client: " << clienti[i].getNume() << ") a fost anulata.\n";
                clienti.erase(clienti.begin() + i);
                return true;
            }
        }
        cout << "Nu exista rezervare pentru camera " << nrCamera << ".\n";
        return false;
    }

    bool anuleazaRezervareClient(string numeClient) { 
        for (size_t i = 0; i < clienti.size(); ++i) {
            if (clienti[i].getNume() == numeClient) {
                cout << "Rezervarea clientului " << numeClient << " a fost anulata camera "
                    << clienti[i].getNumarCamera() << ").\n";
                clienti.erase(clienti.begin() + i);
                return true;
            }
        }
        cout << "Nu am gasit rezervare pentru clientul " << numeClient << ".\n";
        return false;
    }

    void afiseazaClienti() const { 
        if (clienti.empty()) { cout << "Nu exista clienti cazati.\n"; return; }
        cout << "\nLista clienti cazati:\n";
        for (const auto& c : clienti) c.afiseaza();
    }

    bool afiseazaClientLaCamera(int nrCamera) const {  
        for (const auto& c : clienti) {
            if (c.getNumarCamera() == nrCamera) {
                cout << "La camera " << nrCamera << " este cazat:\n";
                c.afiseaza();
                return true;
            }
        }
        cout << "Camera " << nrCamera << " este libera.\n";
        return false;
    }

    bool cautaClient(string numeCautat) const {
        for (const auto& c : clienti) {
            if (c.getNume() == numeCautat) {
                cout << "\nClient gasit:\n";
                c.afiseaza();
                return true;
            }
        }
        cout << "\nClientul " << numeCautat << " nu a fost gasit.\n";
        return false;
    }

    int totalNoptiRezervate() const {
        int total = 0;
        for (const auto& c : clienti) {
            total += c.getZileSejur();
        }
        return total;
    }

};


// ititializam variabila statica
int Hotel::totalHoteluri = 0;

int main() {

    Hotel h("Hilton", "Bucuresti", 10, 0);

    h.rezervaCamera("Ion Popescu", 34, 3, 5);   
    h.rezervaCamera("Maria Ionescu", 28, 5, 2); 
    h.rezervaCamera("Alex Georgescu", 41, 3, 1);

    h.afiseazaInfo();     
    h.afiseazaClienti();  
    cout << "\ntotal nopti rezervate: " << h.totalNoptiRezervate() << "\n";
    h.afiseazaClientLaCamera(5);
    h.cautaClient("Ion Popescu");
    h.cautaClient("Gigel");

    h.anuleazaRezervareCamera(5);    
    h.afiseazaInfo();            

    cout << "\nTotal hoteluri: " << Hotel::getTotalHoteluri() << "\n"; 
    return 0;

    return 0;
}