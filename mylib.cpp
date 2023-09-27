#include "header.h"
//------------------------------------------------------------------------------------
int randint(int nuo, int iki) {
    return nuo + rand() % (iki - nuo + 1);
}
//------------------------------------------------------------------------------------
double skaiciuotiGalutini(Studentas& studentas) {
    double suma = 0;
    for (int pazymys : studentas.nd) {
        suma += pazymys;
    }
    int pazymiuSkaicius = studentas.nd.size();
    return (suma / pazymiuSkaicius) * 0.4 + studentas.egz;
}
//------------------------------------------------------------------------------------
double skaiciuotiMediana(Studentas& studentas) {
    sort(studentas.nd.begin(), studentas.nd.end());
    int pazymiuSkaicius = studentas.nd.size();

    if (pazymiuSkaicius % 2 == 0) {
        int vidurinis1 = studentas.nd[pazymiuSkaicius / 2 - 1];
        int vidurinis2 = studentas.nd[pazymiuSkaicius / 2];
        return (vidurinis1 + vidurinis2) / 2.0;
    } else {
        return studentas.nd[pazymiuSkaicius / 2];
    }
}

//------------------------------------------------------------------------------------
void nuskaitytiIsFailo(vector<Studentas>& studentai) {
    ifstream input("kursiokai.txt"); // Atidaryti failą skaitymui
    if (!input.is_open()) {
        cout << "Klaida atidarant faila!" << endl;
        return;
    }

    string header;
    getline(input, header); // Nuskaityti antraštę

    while (!input.eof()) {
        Studentas studentas;
        input >> studentas.Vardas >> studentas.Pavarde;
        for (int i = 0; i < 5; i++) {
            int pazymys;
            input >> pazymys;
            studentas.nd.push_back(pazymys);
        }
        input >> studentas.egz;
        studentas.galutinis = skaiciuotiGalutini(studentas);

                studentas.mediana = skaiciuotiMediana(studentas);

        studentai.push_back(studentas);
    }

    input.close(); // Uždaryti failą
}
//------------------------------------------------------------------------------------

void ivestis(vector<Studentas>& studentai) {
    int pazymys;
    while (true) {
        cout << "Ar norite nuskaityti duomenis is failo? (taip - 1, ne - 0): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            nuskaitytiIsFailo(studentai);
            break;
        } else {
            Studentas studentas;

            cout << "Iveskite studento varda (Vardas): ";
            cin >> studentas.Vardas;

            cout << "Iveskite studento pavarde (Pavarde): ";
            cin >> studentas.Pavarde;

            // Pasirinkti ar automatiskai irasyti egzamino rezultata
        cout << "Ar norite automatiskai irasyti egzamino rezultata? (taip - 1, ne - 0): ";
        int choice1;
        cin >> choice1;
        if (choice1 == 1) {
            studentas.egz=randint(1, 10);
        } else {
        cout << "Įveskite studento egzamino rezultatą (egz): ";
        cin >> studentas.egz;
        }
        // Pažymių (nd) įvedimas
        studentas.nd.clear(); // Išvalyti esamus pažymius

        // Pasirinkti ar automatiskai pildyti namų darbus
        cout << "Ar norite automatiskai pildyti namu darbus? (taip - 1, ne - 0): ";
        int choice2;
        cin >> choice2;

        if (choice2 == 1) {
            cout << "Koki kieki namu darbu sugeneruoti? ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                pazymys = randint(1, 10); 
                studentas.nd.push_back(pazymys);
            }
        } else {
            while (true) {
                cout << "Įveskite pažymį (arba -1, jei norite baigti): ";
                cin >> pazymys;

                if (pazymys == -1) {
                    break; // Išeiti iš ciklo, jei įvesta -1
                }

                studentas.nd.push_back(pazymys);
            }
        }

                studentas.galutinis = skaiciuotiGalutini(studentas);

                studentas.mediana = skaiciuotiMediana(studentas);

            // Pridėti studentą į sąrašą
            studentai.push_back(studentas);

            cout << "Ar norite ivesti kita studenta? (taip - 1, ne - 0): ";
            int choice4;
            cin >> choice4;

            if (choice4 == 0) {
                break; // Baigti įvedimą, jei pasirinkta "ne"
            }
        }
    }
}
//------------------------------------------------------------------------------------

void spausdinti(vector<Studentas>& studentai) {
    // Atvaizduoti studentų duomenis
    int choice;
    cout << "Norite naudoti meadiana ar galutini pazymi? (Mediana - 1, Galutinis - 0): ";
    cin >> choice;
    printf("%s %s %s\n", "Vardas", "Pavarde", (choice == 1) ? "Mediana" : "Galutinis");
    for (const Studentas& studentas : studentai) {
        printf("%s %s %.2f\n", studentas.Vardas.c_str(), studentas.Pavarde.c_str(),
            (choice == 1) ? studentas.mediana : studentas.galutinis);
    }
}
//------------------------------------------------------------------------------------




