#include "header.h"
#include "timer.h"

int main() {
    vector<vector<Studentas>> studentai(5);
    vector<vector<Studentas>> bahurai(5);
    vector<vector<Studentas>> slabakai(5);
    vector<Studentas> studentai_ivedimas;
    char choice;
    char choice2;


    cout << "Norite naudoti mediana ar vidurki ? (Mediana - a, Vidurkis - b): ";
    ived_tikr_a_or_b(choice);
    cout << "Norite naudoti ivedima ranka ar generuoti failus ? (ranka - a, generuoti - b): ";
    ived_tikr_a_or_b(choice2);
    if (choice2=='a')
    {
        ivestis(studentai_ivedimas);

    //Isrikiuoti pagal varda pavarde
    rikiuoti(studentai_ivedimas, choice);

    // Atvaizduoti studentų duomenis
    spausdinti(studentai_ivedimas,"ranka_rezultat",choice);

    }
    else{

    // Comment out or remove the generavimas lines if not needed
    // generavimas(1000, 5, "stud_1000.txt");
    // generavimas(10000, 5, "stud_10000.txt");
    // generavimas(100000, 5, "stud_100000.txt");
    // generavimas(1000000, 5, "stud_1000000.txt");
    // generavimas(10000000, 5, "stud_10000000.txt");

    Timer timer;

    for (int i = 0; i < 5; ++i) {
        int numStudents = pow(10, i + 3); // 1000, 10000, 100000, 1000000, 10000000

        cout << "Laikai su " << numStudents << " studentu:" << endl;

        timer.reset();
        nuskaitytiIsFailo(studentai[i], "stud_" + to_string(numStudents) + ".txt");
        cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        isskirstymas(studentai[i], bahurai[i], slabakai[i], choice);
        cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(bahurai[i], choice);
        cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(slabakai[i], choice);
        cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(bahurai[i], "results" + to_string(numStudents) + "_1.txt", choice);
        cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(slabakai[i], "results" + to_string(numStudents) + "_2.txt", choice);
        cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    }
    }
    return 0;
}

