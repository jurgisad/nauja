#include "header.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai;
    // Ivesti studentus
    ivestis(studentai);

    //Isrikiuoti pagal varda pavarde
    rikiuoti(studentai);
    
    // Atvaizduoti studentų duomenis
    spausdinti(studentai);

    return 0;
}
