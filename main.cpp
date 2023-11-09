#include "header.h"
#include "timer.h"

int main() {
    list<Studentas> studentai_1000;
    list<Studentas> studentai_10000;
    list<Studentas> studentai_100000;
    list<Studentas> studentai_1000000;
    list<Studentas> studentai_10000000;

    list<Studentas> bahurai_1000;
    list<Studentas> bahurai_10000;
    list<Studentas> bahurai_100000;
    list<Studentas> bahurai_1000000;
    list<Studentas> bahurai_10000000;

    list<Studentas> slabakai_1000;
    list<Studentas> slabakai_10000;
    list<Studentas> slabakai_100000;
    list<Studentas> slabakai_1000000;
    list<Studentas> slabakai_10000000;

    list<Studentas> studentai_ivedimas_l;

    vector<vector<Studentas>> studentai(5);
    vector<vector<Studentas>> bahurai(5);
    vector<vector<Studentas>> slabakai(5);
    vector<Studentas> studentai_ivedimas;
    char choice;
    char choice2;
    char choice3;


    cout << "Norite naudoti mediana ar vidurki ? (Mediana - a, Vidurkis - b): ";
    ived_tikr_a_or_b(choice);
    cout << "Norite naudoti ivedima ranka ar generuoti failus ? (ranka - a, generuoti - b): ";
    ived_tikr_a_or_b(choice2);
    cout << "Norite naudoti sarasus ar vektorius? (sarasus - a, vektorius - b): ";
    ived_tikr_a_or_b(choice3);

    if(choice3=='b')
    {
        if (choice2=='a')
    {
        ivestis(studentai_ivedimas_l);

    //Isrikiuoti pagal varda pavarde
    rikiuoti(studentai_ivedimas_l, choice);

    // Atvaizduoti studentų duomenis
    spausdinti(studentai_ivedimas_l,"ranka_rezultat",choice);

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

    if (i == 0) {
        timer.reset();
        nuskaitytiIsFailo(studentai_1000, "stud_" + to_string(numStudents) + ".txt");
        cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        isskirstymas(studentai_1000, bahurai_1000, slabakai_1000, choice);
        cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(bahurai_1000, choice);
        cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(slabakai_1000, choice);
        cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(bahurai_1000, "results" + to_string(numStudents) + "_11.txt", choice);
        cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(slabakai_1000, "results" + to_string(numStudents) + "_22.txt", choice);
        cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;

    } else if (i == 1) {
        timer.reset();
        nuskaitytiIsFailo(studentai_10000, "stud_" + to_string(numStudents) + ".txt");
        cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        isskirstymas(studentai_10000, bahurai_10000, slabakai_10000, choice);
        cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(bahurai_10000, choice);
        cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(slabakai_10000, choice);
        cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(bahurai_10000, "results" + to_string(numStudents) + "_11.txt", choice);
        cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(slabakai_10000, "results" + to_string(numStudents) + "_22.txt", choice);
        cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;

    } else if (i == 2) {
        timer.reset();
        nuskaitytiIsFailo(studentai_100000, "stud_" + to_string(numStudents) + ".txt");
        cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        isskirstymas(studentai_100000, bahurai_100000, slabakai_100000, choice);
        cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(bahurai_100000, choice);
        cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(slabakai_100000, choice);
        cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(bahurai_100000, "results" + to_string(numStudents) + "_11.txt", choice);
        cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(slabakai_100000, "results" + to_string(numStudents) + "_22.txt", choice);
        cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;

    } else if (i == 3) {
        timer.reset();
        nuskaitytiIsFailo(studentai_1000000, "stud_" + to_string(numStudents) + ".txt");
        cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        isskirstymas(studentai_1000000, bahurai_1000000, slabakai_1000000, choice);
        cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(bahurai_1000000, choice);
        cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(slabakai_1000000, choice);
        cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(bahurai_1000000, "results" + to_string(numStudents) + "_11.txt", choice);
        cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(slabakai_1000000, "results" + to_string(numStudents) + "_22.txt", choice);
        cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;

    } else if (i == 4) {
        timer.reset();
        nuskaitytiIsFailo(studentai_10000000, "stud_" + to_string(numStudents) + ".txt");
        cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        isskirstymas(studentai_10000000, bahurai_10000000, slabakai_10000000, choice);
        cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(bahurai_10000000, choice);
        cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        rikiuoti(slabakai_10000000, choice);
        cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(bahurai_10000000, "results" + to_string(numStudents) + "_11.txt", choice);
        cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(slabakai_10000000, "results" + to_string(numStudents) + "_22.txt", choice);
        cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    }

    // Perform other operations specific to each case
}
    }}

    else{
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

    for (int i = 0; i < 1; ++i) {
        int numStudents = pow(10, i + 3); // 1000, 10000, 100000, 1000000, 10000000

        cout << "Laikai su " << numStudents << " studentu:" << endl;

        timer.reset();
        nuskaitytiIsFailo(studentai[i], "stud_" + to_string(numStudents) + ".txt");
        cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;
        //sortStudents(studentai[i], choice);

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
        spausdinti(bahurai[i], "results" + to_string(numStudents) + "_11.txt", choice);
        cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

        timer.reset();
        spausdinti(slabakai[i], "results" + to_string(numStudents) + "_22.txt", choice);
        cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    }
    }
    }

    return 0;
}

