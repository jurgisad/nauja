#include "header.h"
#include "timer.h"

int main() {
    vector<Studentas> studentai1, studentai2, studentai3, studentai4, studentai5;
    vector<Studentas> studentai1_bahurai, studentai2_bahurai, studentai3_bahurai, studentai4_bahurai, studentai5_bahurai;
    vector<Studentas> studentai1_slabakai, studentai2_slabakai, studentai3_slabakai, studentai4_slabakai, studentai5_slabakai;

    char choice;
    cout << "Norite naudoti mediana ar vidurki ? (Mediana - a, Vidurkis - b): ";
    ived_tikr_a_or_b(choice);

    generavimas(1000, 5, "stud_1000.txt");
    generavimas(10000, 5, "stud_10000.txt");
    generavimas(100000, 5, "stud_100000.txt");
    generavimas(1000000, 5, "stud_1000000.txt");
    generavimas(10000000, 5, "stud_10000000.txt");

    Timer timer; // Create a Timer instance

    timer.reset(); // Reset the timer
    cout << "Laikai su 1000 studentu:" << endl;

    nuskaitytiIsFailo(studentai1, "stud_1000.txt");
    cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset(); // Reset the timer

    isskirstymas(studentai1, studentai1_bahurai, studentai1_slabakai, choice);
    cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset(); // Reset the timer

    rikiuoti(studentai1_bahurai, choice);
    cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset(); // Reset the timer

    rikiuoti(studentai1_slabakai, choice);
    cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset(); // Reset the timer

    spausdinti(studentai1_bahurai, "results1000_1.txt", choice);
    cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset(); // Reset the timer

    spausdinti(studentai1_slabakai, "results1000_2.txt", choice);
    cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    timer.reset();

    cout << "Laikai su 10000 studentu:" << endl;

    nuskaitytiIsFailo(studentai1, "stud_10000.txt");
    cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    isskirstymas(studentai2, studentai2_bahurai, studentai2_slabakai, choice);
    cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai2_bahurai, choice);
    cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai2_slabakai, choice);
    cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai2_bahurai, "results10000_1.txt", choice);
    cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai2_slabakai, "results10000_2.txt", choice);
    cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    timer.reset();

    cout << "Laikai su 100000 studentu:" << endl;

    nuskaitytiIsFailo(studentai3, "stud_100000.txt");
    cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    isskirstymas(studentai3, studentai3_bahurai, studentai3_slabakai, choice);
    cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai3_bahurai, choice);
    cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai3_slabakai, choice);
    cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai3_bahurai, "results100000_1.txt", choice);
    cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai3_slabakai, "results100000_2.txt", choice);
    cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    timer.reset();

    cout << "Laikai su 1000000 studentu:" << endl;

    nuskaitytiIsFailo(studentai4, "stud_1000000.txt");
    cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    isskirstymas(studentai4, studentai4_bahurai, studentai4_slabakai, choice);
    cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai4_bahurai, choice);
    cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai4_slabakai, choice);
    cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai4_bahurai, "results1000000_1.txt", choice);
    cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai4_slabakai, "results1000000_2.txt", choice);
    cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    timer.reset();

    cout << "Laikai su 10000000 studentu:" << endl;

    nuskaitytiIsFailo(studentai5, "stud_10000000.txt");
    cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    isskirstymas(studentai5, studentai5_bahurai, studentai5_slabakai, choice);
    cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai5_bahurai, choice);
    cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai5_slabakai, choice);
    cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai5_bahurai, "results10000000_1.txt", choice);
    cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai5_slabakai, "results10000000_2.txt", choice);
    cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
    timer.reset();

    return 0;
}
