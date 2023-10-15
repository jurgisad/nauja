#include "header.h"

int main() {
    //srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai1, studentai2, studentai3, studentai4, studentai5;
    vector<Studentas> studentai1_bahurai, studentai2_bahurai, studentai3_bahurai, studentai4_bahurai, studentai5_bahurai;
    vector<Studentas> studentai1_slabakai, studentai2_slabakai, studentai3_slabakai, studentai4_slabakai, studentai5_slabakai;

    char choice;
    cout << "Norite naudoti mediana ar vidurki ? (Mediana - a, Vidurkis - b): ";
    ived_tikr_a_or_b(choice);

    // Ivesti studentus
    //ivestis(studentai);
    
    //sugeneruoti vektorius
    generavimas(studentai1,1000);
    generavimas(studentai2,10000);
    generavimas(studentai3,100000);
    generavimas(studentai4,1000000);
    generavimas(studentai5,10000000);
    //isskirstyti pagal pazymius
    isskirstymas(studentai1, studentai1_bahurai, studentai1_slabakai, choice);
    isskirstymas(studentai2, studentai2_bahurai, studentai2_slabakai, choice);
    isskirstymas(studentai3, studentai3_bahurai, studentai3_slabakai, choice);
    isskirstymas(studentai4, studentai4_bahurai, studentai4_slabakai, choice);
    isskirstymas(studentai5, studentai5_bahurai, studentai5_slabakai, choice);

    //Isrikiuoti pagal varda pavarde
    //rikiuoti(studentai);

    // Atvaizduoti studentų duomenis
    //spausdinti(studentai1_bahurai,"results1000_1.txt", choice);
    //spausdinti(studentai1_slabakai,"results1000_2.txt", choice);



    return 0;
}
