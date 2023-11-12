#include "header.h"
#include "timer.h"

int main()
{
    list<Studentas> studentai_ivedimas_l;
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

    if(choice3=='a')
    {
        if (choice2=='a')
        {
            ivestis(studentai_ivedimas_l);


            rikiuoti(studentai_ivedimas_l, choice);


            spausdinti(studentai_ivedimas_l,"ranka_rezultat",choice);

        }
        else
        {

            // Uncomment if needed
            // generavimas(1000, 5, "stud_1000.txt");
            // generavimas(10000, 5, "stud_10000.txt");
            // generavimas(100000, 5, "stud_100000.txt");
            // generavimas(1000000, 5, "stud_1000000.txt");
            // generavimas(10000000, 5, "stud_10000000.txt");

            Timer timer;
            for (int i = 0; i < 5; ++i)
            {
                int numStudents = std::pow(10, i + 3);
                std::cout << "Laikai su " << numStudents << " studentu:" << std::endl;
                processStudentData(numStudents, choice);
            }
        }
    }

    else
    {
        if (choice2=='a')
        {
            ivestis(studentai_ivedimas);


            rikiuoti(studentai_ivedimas, choice);


            spausdinti(studentai_ivedimas,"ranka_rezultat",choice);

        }
        else
        {

            // Uncomment if needed
            // generavimas(1000, 5, "stud_1000.txt");
            // generavimas(10000, 5, "stud_10000.txt");
            // generavimas(100000, 5, "stud_100000.txt");
            // generavimas(1000000, 5, "stud_1000000.txt");
            // generavimas(10000000, 5, "stud_10000000.txt");

            Timer timer;

            for (int i = 0; i < 5; ++i)
            {
                int numStudents = std::pow(10, i + 3);
                std::cout << "Laikai su " << numStudents << " studentu:" << std::endl;
                processStudentData_vector(numStudents, choice);
            }
        }
    }
    return 0;
}
