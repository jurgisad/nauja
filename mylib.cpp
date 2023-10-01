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
    if (pazymiuSkaicius == 0) {
        return studentas.egz*0.6;
    } else{
    return (suma / pazymiuSkaicius) * 0.4 + studentas.egz*0.6;}
}
//------------------------------------------------------------------------------------
double skaiciuotiMediana(Studentas& studentas)
{
    sort(studentas.nd.begin(), studentas.nd.end());
    int pazymiuSkaicius = studentas.nd.size();
    if (pazymiuSkaicius == 0) {
        return 0.0;
    }

    if (pazymiuSkaicius % 2 == 0)
    {
        int vidurinis1 = studentas.nd[pazymiuSkaicius / 2 - 1];
        int vidurinis2 = studentas.nd[pazymiuSkaicius / 2];
        return (vidurinis1 + vidurinis2) / 2.0;
    }
    else
    {
        return studentas.nd[pazymiuSkaicius / 2];
    }
}

//------------------------------------------------------------------------------------
void nuskaitytiIsFailo(vector<Studentas>& studentai)
{
    ifstream input("pirmas.txt"); // Atidaryti failą skaitymui
    if (!input.is_open())
    {
        cout << "Klaida atidarant faila!" << endl;
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
char getValidInputAorB()
{
    char input;

    do
    {
        cout << "Iveskite 'a' arba 'b': ";
        cin >> input;

        if (input == 'a' || input == 'b')
        {
            cout << "You pasirinkote: " << input << endl;
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
}
//------------------------------------------------------------------------------------
bool isAlphabetic(const std::string& str)
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
}
//------------------------------------------------------------------------------------
string getValidVardasPavarde()
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
}
//------------------------------------------------------------------------------------
int getValidInputND()
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
}
//------------------------------------------------------------------------------------
int getValidInputNDskc()
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
}
//------------------------------------------------------------------------------------
int getValidInputEgz()
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
}
//------------------------------------------------------------------------------------
void ivestis(vector<Studentas>& studentai)
{
    int pazymys;
    char choice;

    while (true)
    {
        cout << "Ar norite nuskaityti duomenis is failo? (a - taip, b - ne): ";
        choice = getValidInputAorB();
        if (choice == 'a')
        {
            nuskaitytiIsFailo(studentai);
            break;
        }
        else if (choice == 'b')
        {
            Studentas studentas;

            cout << "Iveskite studento varda (Vardas): ";
            studentas.Vardas=getValidVardasPavarde();

            cout << "Iveskite studento pavarde (Pavarde): ";
            studentas.Pavarde=getValidVardasPavarde();

            // Pasirinkti ar automatiskai irasyti egzamino rezultata
            cout << "Ar norite automatiskai irasyti egzamino rezultata? (a - taip, b - ne): ";
            choice=getValidInputAorB();

            if (choice == 'a')
            {
                studentas.egz = randint(1, 10);
            }
            else if (choice == 'b')
            {
                cout << "Iveskite studento egzamino rezultata (egz): ";
                studentas.egz=getValidInputEgz();
            }

            // Pažymių (nd) įvedimas
            studentas.nd.clear(); // Išvalyti esamus pažymius

            // Pasirinkti ar automatiskai pildyti namų darbus
            cout << "Ar norite automatiskai pildyti namu darbus? (a - taip, b - ne): ";
            choice = getValidInputAorB();

            if (choice == 'a')
            {
                cout << "Koki kieki namu darbu sugeneruoti? ";
          int n=getValidInputNDskc();

                for (int i = 0; i < n; i++)
                {
                    pazymys = randint(1, 10); // Generate a random score between 1 and 10
                    studentas.nd.push_back(pazymys);
                }
            }
            else if (choice == 'b')
            {
                while (true)
                {
                    cout << "Iveskite pazymi (arba 11, jei norite baigti): ";
                    pazymys=getValidInputND();
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
            choice=getValidInputAorB();

            if (choice == 'b')
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
    // Atvaizduoti studentų duomenis
    char choice;
    cout << "Norite naudoti mediana ar galutini pazymi? (Mediana - a, Galutinis - b): ";
    choice=getValidInputAorB();

    cout << "Pasirinkote: " << choice << endl;;
    printf("%-15s %-15s %s\n", "Vardas", "Pavarde", (choice == 'a') ? "Mediana" : "Galutinis");
    cout << "--------------------------------------------" << endl;


    for (const Studentas& studentas : studentai)
    {
        printf("%-15s %-15s %.2f\n", studentas.Vardas.c_str(), studentas.Pavarde.c_str(),
               (choice == 'a') ? studentas.mediana : studentas.galutinis);
    }
}
//------------------------------------------------------------------------------------

