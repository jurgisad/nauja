#include "header.h"

int randint(int nuo, int iki) {
    return nuo + rand() % (iki - nuo + 1);
}

void ivestis(vector<Studentas>& studentai) {
    int pazymys;
    while (true) {
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
                pazymys = randint(1, 10); // Generate a random score between 1 and 10
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

        // Vidurkio (vidurkis) ir medianos (mediana) skaičiavimas pagal įvestį
        double suma = 0;
        for (int pazymys : studentas.nd) {
            suma += pazymys;
        }
        int pazymiuSkaicius = studentas.nd.size();

        if (pazymiuSkaicius > 0) {
            studentas.galutinis = (suma / pazymiuSkaicius) * 0.4 + studentas.egz;
            // Pažymiai surūšiuojami medianos skaičiavimui
            sort(studentas.nd.begin(), studentas.nd.end());

            if (pazymiuSkaicius % 2 == 0) {
                // Jei yra lyginis pažymių skaičius, imamas dviejų vidurinių pažymių vidurkis
                int vidurinis1 = studentas.nd[pazymiuSkaicius / 2 - 1];
                int vidurinis2 = studentas.nd[pazymiuSkaicius / 2];
                studentas.mediana = (vidurinis1 + vidurinis2) / 2.0;
            } else {
                // Jei yra nelyginis pažymių skaičius, imamas vidurinis pažymys
                studentas.mediana = studentas.nd[pazymiuSkaicius / 2];
            }
        }

        // Pridėti studentą į sąrašą
        studentai.push_back(studentas);

        cout << "Ar norite ivesti kita studenta? (taip - 1, ne - 0): ";
        int choice3;
        cin >> choice3;

        if (choice3 == 0) {
            break; // Baigti įvedimą, jei pasirinkta "ne"
        }
    }
}

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




