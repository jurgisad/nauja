#include "header.h"
//------------------------------------------------------------------------------------
int randint(int nuo, int iki)
{
    return nuo + rand() % (iki - nuo + 1);
}
//------------------------------------------------------------------------------------
double skaiciuotiGalutini(Studentas& studentas)
{
    double suma = 0;
    for (int pazymys : studentas.nd)
    {
        suma += pazymys;
    }
    int pazymiuSkaicius = studentas.nd.size();

    try {
        if (pazymiuSkaicius == 0) {
            throw std::runtime_error("Dalyba is nulio, grazintas tik egzamino rezultatas.");
        } else {
            return (suma / pazymiuSkaicius) * 0.4 + studentas.egz * 0.6;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return studentas.egz * 0.6;; 
    }
}

//------------------------------------------------------------------------------------
double skaiciuotiMediana(Studentas& studentas)
{
    sort(studentas.nd.begin(), studentas.nd.end());
    int pazymiuSkaicius = studentas.nd.size();
    if (pazymiuSkaicius == 0)
    {
        return studentas.egz*0.6;
    }

    if (pazymiuSkaicius % 2 == 0)
    {
        int vidurinis1 = studentas.nd[pazymiuSkaicius / 2 - 1];
        int vidurinis2 = studentas.nd[pazymiuSkaicius / 2];
        return ((vidurinis1 + vidurinis2) / 2.0)*0.4+studentas.egz*0.6;
    }
    else
    {
        return studentas.nd[pazymiuSkaicius / 2]*0.4+studentas.egz*0.6;
    }
}

//------------------------------------------------------------------------------------
void nuskaitytiIsFailo(vector<Studentas>& studentai)
{
    string failas;
    system("dir *.txt");
    cout<<"kuri faila naudosite?"<< endl;
    cin>> failas;
    ifstream input(failas); // Atidaryti failą skaitymui
    if (!input.is_open())
    {
        cerr << "Klaida atidarant faila!" << endl;
        return;
    }

    string header;
    getline(input, header); // Nuskaityti antraštę

    while (!input.eof())
    {
        Studentas studentas;
        input >> studentas.Vardas >> studentas.Pavarde;
        while (true)
        {
            int pazymys;
            input >> pazymys;
            if (input.fail() || input.peek() == '\n' || input.peek() == EOF)
            {
                studentas.egz = pazymys; //"egz"
                break;
            }

            studentas.nd.push_back(pazymys);
        }
        studentas.galutinis = skaiciuotiGalutini(studentas);

        studentas.mediana = skaiciuotiMediana(studentas);

        studentai.push_back(studentas);
    }

    input.close(); // Uždaryti failą
}
//------------------------------------------------------------------------------------
void ived_tikr(auto &a)
{
    cin>>a;
       do
    {
        try
        {
            if (cin.fail())
            {
                throw std::runtime_error("ivedete ne ta duomeni");

            }
        }

        catch (const std::runtime_error& e)
        {
            cout<< e.what();
            std::cin.clear();
            std::cin.ignore(256,'\n');
            cin>>a;
        }
    }
    while (cin.fail()==true);
}
//------------------------------------------------------------------------------------
void ived_tikr_a_or_b(char &a)
{
    while (true)
    {
        ived_tikr(a);

        if (cin.peek() == '\n')
        {
            cin.ignore(); // Clear the newline character
        }
        else
        {
            cerr << "Ivestis turi buti tik vienas simbolis 'a' arba 'b'. Bandykite vel: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            continue;
        }

        if (a == 'a' || a == 'b')
        {
            break;
        }
        else
        {
            cerr << "Ivestis turi buti 'a' arba 'b'. Bandykite vel: ";
        }
    }
}



//------------------------------------------------------------------------------------
void ived_tikr_nd(int &a)
{
    ived_tikr(a);

    while (a < 0 || a > 11)
    {
        cerr << "Ivestis turi buti sveikas skaicius nuo 0 iki 11. Bandykite vel: ";
        ived_tikr(a);
    }
}
//------------------------------------------------------------------------------------
void ived_tikr_egz(int &a)
{
    ived_tikr(a);

    while (a < 0 || a > 10)
    {
        cerr << "Ivestis turi buti sveikas skaicius nuo 0 iki 10. Bandykite vel: ";
        ived_tikr(a);
    }
}
//------------------------------------------------------------------------------------
/*string getValidInputAorB()
{
    string input;

    do
    {
        cout << "Iveskite 'a' arba 'b': ";
        cin >> input;

        if (input.length() ==1 && (input == "a" || input == "b"))
        {
            cout << "Jus pasirinkote: " << input << endl;
            return input; // Grazina gera ivesti
        }
        else
        {
            cout << "Negalimas pasirinkimas, bandykite dar karta." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Pasalina ivesties buferi
        }
    }
    while (true);
}*/
//------------------------------------------------------------------------------------
/*bool isAlphabetic(const std::string& str)
{
    // Ar alfabetinis string
    for (char c : str)
    {
        if (!std::isalpha(c))
        {
            return false;
        }
    }
    return true;
}*/
//------------------------------------------------------------------------------------
/*string getValidVardasPavarde()
{
    string input;

    do
    {
        cin >> input;

        if (isAlphabetic(input) && input.length() >= 2)
        {
            cout << "You pasirinkote: " << input << endl;
            return input; // Grazina gera ivesti
        }
        else
        {
            cout << "Negalimas pasirinkimas, bandykite dar karta naudodami tik raides" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Pasalina ivesties buferi
        }
    }
    while (true);
}*/
//------------------------------------------------------------------------------------
/*int getValidInputND()
{
    string inputStr;

    while (true)
    {
        cout << "Iveskite sveika skaiciu nuo 0 iki 11: ";
        cin >> inputStr;

        bool isInteger = true;

        for (char c : inputStr)
        {
            if (!isdigit(c))
            {
                isInteger = false;
                break;
            }
        }

        if (!isInteger)
        {
            cout << "Netinkama ivestis, bandykite dar karta." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            int input = stoi(inputStr);
            if (input < 0 || input > 11)
            {
                cout << "Netinkama ivestis, bandykite dar karta." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                return input;
            }
        }
    }
}*/
//------------------------------------------------------------------------------------
/*int getValidInputNDskc()
{
    string inputStr;

    while (true)
    {
        cout << "Iveskite skaiciu: ";
        cin >> inputStr;

        bool isInteger = true;

        for (char c : inputStr)
        {
            if (!isdigit(c))
            {
                isInteger = false;
                break;
            }
        }

        if (!isInteger)
        {
            cout << "Netinkama ivestis, bandykite dar karta." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            int input = stoi(inputStr);
            return input;
        }
    }
}*/
//------------------------------------------------------------------------------------
/*int getValidInputEgz()
{
    string inputStr;

    while (true)
    {
        cout << "Iveskite sveika skaiciu nuo 0 iki 10: ";
        cin >> inputStr;

        bool isInteger = true;

        for (char c : inputStr)
        {
            if (!isdigit(c))
            {
                isInteger = false;
                break;
            }
        }

        if (!isInteger)
        {
            cout << "Netinkama ivestis, bandykite dar karta." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            int input = stoi(inputStr);
            if (input < 0 || input > 10)
            {
                cout << "Netinkama ivestis, bandykite dar karta." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                return input;
            }
        }
    }
}*/
//------------------------------------------------------------------------------------
void ivestis(vector<Studentas>& studentai)
{
    int pazymys;
    string choice;


    while (true)
    {
        cout << "Ar norite nuskaityti duomenis is failo? (a - taip, b - ne): ";
        char choice1;
        ived_tikr_a_or_b(choice1);

        if (choice1 == 'a')
        {
            nuskaitytiIsFailo(studentai);
            break;
        }
        else if (choice1 == 'b')
        {
            Studentas studentas;

            cout << "Iveskite studento varda (Vardas): ";
            ived_tikr(studentas.Vardas);

            cout << "Iveskite studento pavarde (Pavarde): ";
            ived_tikr(studentas.Pavarde);

            // Pasirinkti ar automatiskai irasyti egzamino rezultata
            cout << "Ar norite automatiskai irasyti egzamino rezultata? (a - taip, b - ne): ";
            char choice2;
        ived_tikr_a_or_b(choice2);

            if (choice2 == 'a')
            {
                studentas.egz = randint(1, 10);
            }
            else if (choice2 == 'b')
            {
                cout << "Iveskite studento egzamino rezultata (egz): ";
                ived_tikr_egz(studentas.egz);
            }

            // Pažymių (nd) įvedimas
            studentas.nd.clear(); // Išvalyti esamus pažymius

            // Pasirinkti ar automatiskai pildyti namų darbus
            cout << "Ar norite automatiskai pildyti namu darbus? (a - taip, b - ne): ";
            char choice3;
        ived_tikr_a_or_b(choice3);
            if (choice3 == 'a')
            {
                cout << "Koki kieki namu darbu sugeneruoti? ";
                int n;
                ived_tikr(n);

                for (int i = 0; i < n; i++)
                {
                    pazymys = randint(1, 10); // Generate a random score between 1 and 10
                    studentas.nd.push_back(pazymys);
                }
            }
            else if (choice3 == 'b')
            {
                while (true)
                {
                    cout << "Iveskite pazymi (arba 11, jei norite baigti): ";
                   ived_tikr_nd(pazymys);
                    if (pazymys == 11)
                    {
                        break; // Išeiti iš ciklo, jei įvesta 11
                    }

                    studentas.nd.push_back(pazymys);
                }
            }

            studentas.galutinis = skaiciuotiGalutini(studentas);
            studentas.mediana = skaiciuotiMediana(studentas);

            // Pridėti studentą į sąrašą
            studentai.push_back(studentas);

            cout << "Ar norite ivesti kita studenta? (a - taip, b - ne): ";
            char choice4;
        ived_tikr_a_or_b(choice4);

            if (choice4 == 'b')
            {
                break; // Baigti įvedimą, jei pasirinkta "ne"
            }
        }
    }
}
//------------------------------------------------------------------------------------
bool palyginimas(const Studentas& a, const Studentas& b)
{
    if (a.Vardas == b.Vardas)
    {
        return a.Pavarde < b.Pavarde;
    }
    return a.Vardas < b.Vardas;
}
//------------------------------------------------------------------------------------
void rikiuoti(vector<Studentas>& studentai)
{
// Sort studentai
    sort(studentai.begin(), studentai.end(), palyginimas);
}
//------------------------------------------------------------------------------------
void spausdinti(vector<Studentas>& studentai)
{
    char choice;
    cout << "Norite naudoti mediana ar vidurki ? (Mediana - a, Vidurkis - b): ";
    ived_tikr_a_or_b(choice);

    ofstream outputFile("result.txt"); // atidaryti output faila

    if (outputFile.is_open())
    {
        outputFile << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << ((choice == 'a') ? "Galutinis (Med)" : "Galutinis (Vid)") << endl;
        outputFile << "--------------------------------------------" << endl;

        for (const Studentas& studentas : studentai)
        {
            outputFile << setw(15) << left << studentas.Vardas << setw(15) << left << studentas.Pavarde << fixed << setprecision(2) << ((choice == 'a') ? studentas.mediana : studentas.galutinis) << endl;
        }

        outputFile.close(); // uzdaryti output faila
        cout << "Rezultatai irasyti i 'result.txt'." << endl;
    }
    else
    {
        cout << "Nepavyko atidaryto failo" << endl;
    }
}
//------------------------------------------------------------------------------------
