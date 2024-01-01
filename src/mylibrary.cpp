#include "header.h"
#include "timer.h"
//------------------------------------------------------------------------------------

int generateRandomNumber2(std::mt19937& mt) {
    // Define a uniform distribution for the range [0, 10]
    std::uniform_int_distribution<int> distribution(0, 10);

    // Generate a random number within the specified range
    int random_number = distribution(mt);

    return random_number;
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

    try
    {
        if (pazymiuSkaicius == 0)
        {
            throw std::runtime_error("Dalyba is nulio, grazintas tik egzamino rezultatas.");
        }
        else
        {
            return (suma / pazymiuSkaicius) * 0.4 + studentas.egz * 0.6;
        }
    }
    catch (const std::runtime_error& e)
    {
        // Handle the division by zero error here
        std::cerr << e.what() << std::endl;
        return studentas.egz * 0.6;; // You can return a default value or handle the error as needed.
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
//su vektoriais
void nuskaitytiIsFailo(vector<Studentas>& studentai, string failas) {
    /*string failas;
    system("dir *.txt");
    cout << "Kuri faila naudosite?" << endl;
    cin >> failas;*/
    ifstream input(failas); // Atidaryti failą skaitymui
    if (!input.is_open()) {
        cerr << "Klaida atidarant faila!" << endl;
        return;
    }

    string header;
    getline(input, header); // Nuskaityti antraštę

    while (!input.eof() && !input.fail()) {
        Studentas studentas;
        input >> studentas.Vardas >> studentas.Pavarde;
        if (input.fail()) {
            break;
        }

        while (true) {
            int pazymys;
            input >> pazymys;

            if (input.fail() || input.peek() == '\n' || input.peek() == EOF) {
                studentas.egz = pazymys;
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
//su listais
void nuskaitytiIsFailo(list<Studentas>& studentai, string failas) {
    ifstream input(failas); // Open the file for reading

    if (!input.is_open()) {
        cerr << "Klaida atidarant faila!" << endl;
        return;
    }

    string header;
    getline(input, header); // Read the header line (if there's any)

    while (!input.eof() && !input.fail()) {
        Studentas studentas;
        input >> studentas.Vardas >> studentas.Pavarde;

        if (input.fail()) {
            break;
        }

        while (true) {
            int pazymys;
            input >> pazymys;

            if (input.fail() || input.peek() == '\n' || input.peek() == EOF) {
                studentas.egz = pazymys;
                break;
            }

            studentas.nd.push_back(pazymys);
        }

        studentas.galutinis = skaiciuotiGalutini(studentas);
        studentas.mediana = skaiciuotiMediana(studentas);

        studentai.push_back(studentas);  // Add the student to the list
    }

    input.close(); // Close the file
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
void generavimas(int studentuskc, int namuDarbuKiekis, string failas) {
    std::mt19937 mt(std::random_device{}());
    ofstream outputFile(failas);

    int columnWidth = 15;

    outputFile << left << setw(columnWidth) << "Vardas" << setw(columnWidth) << "Pavarde";
    for (int i = 1; i <= namuDarbuKiekis; i++) {
        outputFile << setw(columnWidth) << "ND" + to_string(i);
    }
    outputFile << "Egz.\n";  // Add a newline character here

    for (int i = 1; i <= studentuskc; i++) {
        Studentas studentas;
        studentas.Vardas = "Vardas" + to_string(i);
        studentas.Pavarde = "Pavarde" + to_string(i);
        studentas.egz = generateRandomNumber2(mt);

        outputFile << left << setw(columnWidth) << studentas.Vardas << setw(columnWidth) << studentas.Pavarde;
        for (int j = 0; j < namuDarbuKiekis; j++) {
            int nd = generateRandomNumber2(mt);
            studentas.nd.push_back(nd);
            outputFile << setw(columnWidth) << nd;
        }
        outputFile <<studentas.egz << '\n';  // Use single quotes to remove extra whitespace
    }

    outputFile.close();
}


//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//Su vektoriais
void isskirstymas(const vector<Studentas>& studentai, vector<Studentas>& geri_studentai, vector<Studentas>& blogi_studentai, char choice) {
    if (choice == 'b') {
        for (const Studentas& studentas : studentai) {
            if (studentas.galutinis >= 5) {
                geri_studentai.push_back(studentas);
            } else {
                blogi_studentai.push_back(studentas);
            }
        }
    } else {
        for (const Studentas& studentas : studentai) {
            if (studentas.mediana >= 5) {
                geri_studentai.push_back(studentas);
            } else {
                blogi_studentai.push_back(studentas);
            }
        }
    }
}
//su Listais
void isskirstymas(const list<Studentas>& studentai, list<Studentas>& geri_studentai, list<Studentas>& blogi_studentai, char choice) {
    if (choice == 'b') {
        for (const Studentas& studentas : studentai) {
            if (studentas.galutinis < 5) {
                blogi_studentai.push_back(studentas);
            } else {
                geri_studentai.push_back(studentas);
            }
        }
    } else {
        for (const Studentas& studentas : studentai) {
            if (studentas.mediana < 5) {
                blogi_studentai.push_back(studentas);
            } else {
                geri_studentai.push_back(studentas);
            }
        }
    }
}
//------------------------------------------------------------------------------------
void ivestis(vector<Studentas>& studentai)
{
    std::mt19937 mt(std::random_device{}());
    int pazymys;
    string choice;


    while (true)
    {
            Studentas studentas;

            cout << "Iveskite studento vardaaaaaaaaaaaaaaaaaaaa (Vardas): ";
            ived_tikr(studentas.Vardas);

            cout << "Iveskite studento pavarde (Pavarde): ";
            ived_tikr(studentas.Pavarde);

            // Pasirinkti ar automatiskai irasyti egzamino rezultata
            cout << "Ar norite automatiskai irasyti egzamino rezultata? (a - taip, b - ne): ";
            char choice2;
            ived_tikr_a_or_b(choice2);

            if (choice2 == 'a')
            {
                studentas.egz = generateRandomNumber2(mt);
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
                    pazymys = generateRandomNumber2(mt); // Generate a random score between 1 and 10
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
           cout << "Memory Address: " << &studentai.back() << "\n";
        cout << "Vardas: " << studentai.back().Vardas << "\n";
        cout << "Pavarde: " << studentai.back().Pavarde << "\n";
        cout << "Egzamino rezultatas: " << studentai.back().egz << "\n";
        cout << "Namu darbu pazymiai: ";
        for (int nd : studentai.back().nd) {
            cout << nd << " ";
        }
        cout << "\n";
        cout << "Galutinis: " << studentai.back().galutinis << "\n";
        cout << "Mediana: " << studentai.back().mediana << "\n";


            cout << "Ar norite ivesti kita studenta? (a - taip, b - ne): ";
            char choice4;
            ived_tikr_a_or_b(choice4);

            if (choice4 == 'b')
            {
                break; // Baigti įvedimą, jei pasirinkta "ne"
            }
        }
    }

//su listais
void ivestis(list<Studentas>& studentai) {
    std::mt19937 mt(std::random_device{}());
    int pazymys;
    string choice;

    while (true) {
        Studentas studentas;

        cout << "Iveskite studento varda (Vardas): ";
        ived_tikr(studentas.Vardas);

        cout << "Iveskite studento pavarde (Pavarde): ";
        ived_tikr(studentas.Pavarde);

        // Pasirinkti ar automatiskai irasyti egzamino rezultata
        cout << "Ar norite automatiskai irasyti egzamino rezultata? (a - taip, b - ne): ";
        char choice2;
        ived_tikr_a_or_b(choice2);

        if (choice2 == 'a') {
            studentas.egz = generateRandomNumber2(mt);
        } else if (choice2 == 'b') {
            cout << "Iveskite studento egzamino rezultata (egz): ";
            ived_tikr_egz(studentas.egz);
        }

        // Pažymių (nd) įvedimas
        studentas.nd.clear(); // Išvalyti esamus pažymius

        // Pasirinkti ar automatiskai pildyti namų darbus
        cout << "Ar norite automatiskai pildyti namu darbus? (a - taip, b - ne): ";
        char choice3;
        ived_tikr_a_or_b(choice3);

        if (choice3 == 'a') {
            cout << "Koki kieki namu darbu sugeneruoti? ";
            int n;
            ived_tikr(n);

            for (int i = 0; i < n; i++) {
                pazymys = generateRandomNumber2(mt); // Generate a random score between 1 and 10
                studentas.nd.push_back(pazymys);
            }
        } else if (choice3 == 'b') {
            while (true) {
                cout << "Iveskite pazymi (arba 11, jei norite baigti): ";
                ived_tikr_nd(pazymys);
                if (pazymys == 11) {
                    break; // Išeiti iš ciklo, jei įvesta 11
                }

                studentas.nd.push_back(pazymys);
            }
        }

        studentas.galutinis = skaiciuotiGalutini(studentas);
        studentas.mediana = skaiciuotiMediana(studentas);



        // Pridėti studentą į sąrašą
        studentai.push_back(studentas);
         cout << "Memory Address: " << &studentai.back() << "\n";
        cout << "Vardas: " << studentai.back().Vardas << "\n";
        cout << "Pavarde: " << studentai.back().Pavarde << "\n";
        cout << "Egzamino rezultatas: " << studentai.back().egz << "\n";
        cout << "Namu darbu pazymiai: ";
        for (int nd : studentai.back().nd) {
            cout << nd << " ";
        }
        cout << "\n";
        cout << "Galutinis: " << studentai.back().galutinis << "\n";
        cout << "Mediana: " << studentai.back().mediana << "\n";

        cout << "Ar norite ivesti kita studenta? (a - taip, b - ne): ";
        char choice4;
        ived_tikr_a_or_b(choice4);

        if (choice4 == 'b') {
            break; // Baigti įvedimą, jei pasirinkta "ne"
        }
    }
}
//------------------------------------------------------------------------------------
void rikiuoti(vector<Studentas>& studentai, char sortBy) {
    sort(studentai.begin(), studentai.end(), [sortBy](const Studentas& c, const Studentas& d) {
        if (sortBy == 'a') { // Sort by average
            return c.mediana < d.mediana;
        }
        if (sortBy == 'b') { // Sort by median
            return c.galutinis < d.galutinis;
        }
        // Default: Sort by Vardas if sortBy is not recognized
        return c.Vardas < d.Vardas; // Add this line for the default case
    });
}
//su listais
void rikiuoti(list<Studentas>& studentai, char sortBy) {
    studentai.sort([sortBy](const Studentas& c, const Studentas& d) {
        if (sortBy == 'a') { // Sort by average
            return c.mediana < d.mediana;
        }
        if (sortBy == 'b') { // Sort by median
            return c.galutinis < d.galutinis;
        }
        // Default: Sort by Vardas if sortBy is not recognized
        return c.Vardas < d.Vardas; // Add this line for the default case
    });
}
//------------------------------------------------------------------------------------
void spausdinti(vector<Studentas>& studentai, string failo_pavad,char choice)
{

    ofstream outputFile(failo_pavad); // atidaryti output faila

    if (outputFile.is_open())
    {
        outputFile << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << ((choice == 'a') ? "Galutinis (Med)" : "Galutinis (Vid)") << endl;
        outputFile << "--------------------------------------------" << endl;

        for (const Studentas& studentas : studentai)
        {
            outputFile << setw(15) << left << studentas.Vardas << setw(15) << left << studentas.Pavarde << fixed << setprecision(2) <<  ((choice == 'a') ? studentas.mediana : studentas.galutinis)<< endl;
        }

        outputFile.close(); // uzdaryti output faila
        //cout << "Rezultatai irasyti i " <<failo_pavad<< endl;
    }
    else
    {
        cout << "Nepavyko atidaryto failo" << endl;
    }
}
//su listais
void spausdinti(list<Studentas>& studentai, string failo_pavad, char choice) {
    ofstream outputFile(failo_pavad); // Open the output file

    if (outputFile.is_open()) {
        outputFile << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << ((choice == 'a') ? "Galutinis (Med)" : "Galutinis (Vid)") << endl;
        outputFile << "--------------------------------------------" << endl;

        for (const Studentas& studentas : studentai)
        {
            outputFile << setw(15) << left << studentas.Vardas << setw(15) << left << studentas.Pavarde << fixed << setprecision(2) <<  ((choice == 'a') ? studentas.mediana : studentas.galutinis)<< endl;
        }


        outputFile.close(); // Close the output file
    //cout << "Rezultatai irasyti i " << failo_pavad << endl;
    } else {
        cout << "Nepavyko atidaryto failo" << endl;
    }
}


//------------------------------------------------------------------------------------
void printElapsedTime(const std::chrono::high_resolution_clock::time_point& start, const std::string& message) {
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << message << " uztruko " << duration << " ms" << std::endl;
}
/*void processStudentData(int numStudents, char choice) {
    list<Studentas> studentai;
    list<Studentas> bahurai;
   // list<Studentas> slabakai;
    string filename = "stud_" + to_string(numStudents) + ".txt";

    Timer timer;

    timer.reset();
    nuskaitytiIsFailo(studentai, filename);
    cout << timer.elapsed()  << endl;

    timer.reset();
    isskirstymas1(studentai, bahurai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    rikiuoti(bahurai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    rikiuoti(studentai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    spausdinti(bahurai, "results" + to_string(numStudents) + "_11.txt", choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    spausdinti(studentai, "results" + to_string(numStudents) + "_22.txt", choice);
    cout << timer.elapsed() <<  endl;
}
void processStudentData_vector(int numStudents, char choice) {
    vector<Studentas> studentai;
    vector<Studentas> bahurai;
  //  vector<Studentas> slabakai;
    string filename = "stud_" + to_string(numStudents) + ".txt";

    Timer timer;

    timer.reset();
    nuskaitytiIsFailo(studentai, filename);
    cout << timer.elapsed()  << endl;

    timer.reset();
    isskirstymas11(studentai, bahurai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    rikiuoti(bahurai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    rikiuoti(studentai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    spausdinti(bahurai, "results" + to_string(numStudents) + "_1.txt", choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    spausdinti(studentai, "results" + to_string(numStudents) + "_2.txt", choice);
    cout << timer.elapsed() <<  endl;
}*/
void processStudentData(int numStudents, char choice) {
    list<Studentas> studentai;
    list<Studentas> bahurai;
    list<Studentas> slabakai;
    string filename = "stud_" + to_string(numStudents) + ".txt";

    Timer timer;

    timer.reset();
    nuskaitytiIsFailo(studentai, filename);
    cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    isskirstymas1(studentai, bahurai,choice);
    cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(bahurai, choice);
    cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai, choice);
    cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(bahurai, "results" + to_string(numStudents) + "_11.txt", choice);
    cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai, "results" + to_string(numStudents) + "_22.txt", choice);
    cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
}
void processStudentData_vector(int numStudents, char choice) {
    vector<Studentas> studentai;
    vector<Studentas> bahurai;
    vector<Studentas> slabakai;
    string filename = "stud_" + to_string(numStudents) + ".txt";

    Timer timer;

    timer.reset();
    nuskaitytiIsFailo(studentai, filename);
    cout << "nuskaityti truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    isskirstymas1(studentai, bahurai,choice);
    cout << "isskirstymas truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(bahurai, choice);
    cout << "rikiuoti bahurus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    rikiuoti(studentai, choice);
    cout << "rikiuoti slabakus truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(bahurai, "results" + to_string(numStudents) + "_11.txt", choice);
    cout << "spausdinti bahurus i faila truko " << timer.elapsed() << " sekundes" << endl;

    timer.reset();
    spausdinti(studentai, "results" + to_string(numStudents) + "_22.txt", choice);
    cout << "spausdinti slabakus i faila truko " << timer.elapsed() << " sekundes" << endl;
}
//-------------------------------------------------------------------------------------------------------//Su vektoriais
void isskirstymas1(vector<Studentas>& studentai, vector<Studentas>& geri_studentai, char choice) {
    if (choice == 'b') {
        auto partition_point = std::partition(studentai.begin(), studentai.end(),
            [](const Studentas& studentas) { return studentas.galutinis >= 5; });

        geri_studentai.insert(geri_studentai.end(), partition_point, studentai.end());

        studentai.erase(partition_point, studentai.end());
    } else {
        auto partition_point = std::partition(studentai.begin(), studentai.end(),
            [](const Studentas& studentas) { return studentas.mediana >= 5; });

        geri_studentai.insert(geri_studentai.end(), partition_point, studentai.end());

        studentai.erase(partition_point, studentai.end());
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------
void isskirstymas1(std::list<Studentas>& studentai, std::list<Studentas>& geri_studentai, char choice) {
    if (choice == 'b') {
        auto partition_point = std::partition(studentai.begin(), studentai.end(),
            [](const Studentas& studentas) { return studentas.galutinis >= 5; });

        geri_studentai.splice(geri_studentai.end(), studentai, partition_point, studentai.end());
    } else {
        auto partition_point = std::partition(studentai.begin(), studentai.end(),
            [](const Studentas& studentas) { return studentas.mediana >= 5; });

        geri_studentai.splice(geri_studentai.end(), studentai, partition_point, studentai.end());
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------
void isskirstymas11(vector<Studentas>& studentai, vector<Studentas>& geri_studentai, char choice) {
    auto condition = (choice == 'b') ? [](const Studentas& studentas) { return studentas.galutinis >= 5; }
                                      : [](const Studentas& studentas) { return studentas.mediana >= 5; };

    auto partition_point = std::partition(studentai.begin(), studentai.end(), condition);

    geri_studentai.insert(geri_studentai.end(),
                          std::make_move_iterator(partition_point),
                          std::make_move_iterator(studentai.end()));

    studentai.erase(partition_point, studentai.end());
}
