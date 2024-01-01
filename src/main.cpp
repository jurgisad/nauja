#include "header.h"
#include "timer.h"
#include "Studentas.h"
#include <sstream>

int main()
{
    vector<Studentas> studentai_ivedimas_s;
    vector<Studentass> studentai_ivedimas_c;
    char choice;
    char choice2;
    char choice3;
    char choice4;

    cout << "Norite naudoti mediana ar vidurki ? (Mediana - a, Vidurkis - b): ";
    ived_tikr_a_or_b(choice);
    cout << "Norite naudoti ivedima ranka ar generuoti failus ? (ranka - a, generuoti - b): ";
    ived_tikr_a_or_b(choice2);
    cout << "Norite naudoti klases ar strukturas? (klases - a, strukturas - b): ";
    ived_tikr_a_or_b(choice3);

    if(choice3=='a')
    {
        if (choice2=='a')
        {
            choice4='a';
            while (choice4=='a')
            {
                Studentass student;
                cout << "Enter student information (vardas pavarde nd1 nd2 ... egz): ";
                cin >> student;
                if (!cin.fail())
                {
                    cout << "Student information entered\n" <<  endl;
                    studentai_ivedimas_c.push_back(student);
                }
                else
                {
                    std::cerr << "Error reading student information." << std::endl;
                }

                cout<<"Ar norite ivesti kita studenta? (Taip - a, Ne - b)"<< endl;
                ived_tikr_a_or_b(choice4);
            }
            rikiuoti_(studentai_ivedimas_c, choice);
            spausdinti_(studentai_ivedimas_c,"ranka_rezultat_c",choice);
        }
        else
        {

            // Comment out or remove the generavimas lines if not needed
            // generavimas(1000, 5, "stud_1000.txt");
            // generavimas(10000, 5, "stud_10000.txt");
            // generavimas(100000, 5, "stud_100000.txt");
            // generavimas(1000000, 5, "stud_1000000.txt");
            // generavimas(10000000, 5, "stud_10000000.txt");

            Timer timer;
            for (int i = 0; i < 4; ++i)
            {
                int numStudents = std::pow(10, i + 3);
                cout << "Laikai su " << numStudents << " studentu:" << endl;
                processStudentData_class(numStudents, choice);
            }

        }
    }

    else
    {
        if (choice2=='a')
        {
            ivestis(studentai_ivedimas_s);


            rikiuoti(studentai_ivedimas_s, choice);


            spausdinti(studentai_ivedimas_s,"ranka_rezultat_s",choice);

        }
        else
        {



            // Comment out or remove the generavimas lines if not needed
            // generavimas(1000, 5, "stud_1000.txt");
            // generavimas(10000, 5, "stud_10000.txt");
            // generavimas(100000, 5, "stud_100000.txt");
            // generavimas(1000000, 5, "stud_1000000.txt");
            // generavimas(10000000, 5, "stud_10000000.txt");

            Timer timer;

            for (int i = 0; i < 4; ++i)
            {
                int numStudents = std::pow(10, i + 3);
                cout << "Laikai su " << numStudents << " studentu:" << endl;
                processStudentData_vector(numStudents, choice);
            }

        }
    }

    cout << "Press Enter to exit...";
    cin.get();
    return 0;
}
