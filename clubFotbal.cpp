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

};

int main() {
    ClubFotbal club1;

    
    ClubFotbal club2("FCSB", "Bucuresti", 1947, 26);

    return 0;
}