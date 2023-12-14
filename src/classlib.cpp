#include "header.h"
#include "Studentas.h"
#include <stdexcept>
#include "timer.h"
#include <iterator>
//---------------------------------------------------------------------------------------
double Studentass::skaiciuotiGalutini1()
{
    double suma = std::accumulate(nd_.begin(), nd_.end(), 0.0);
    int pazymiuSkaicius = nd_.size();

    if (pazymiuSkaicius == 0)
    {
        std::cerr << "Dalyba is nulio, grazintas tik egzamino rezultatas." << std::endl;
        return egz_ * 0.6;
    }

    return (suma / pazymiuSkaicius) * 0.4 + egz_ * 0.6;
}
//---------------------------------------------------------------------------------------
double Studentass::skaiciuotiMediana1()
{

    if (nd_.empty())
    {
        return egz_ * 0.6;
    }


    std::sort(nd_.begin(), nd_.end());

    int pazymiuSkaicius = nd_.size();

    if (pazymiuSkaicius % 2 == 0)
    {
        int vidurinis1 = nd_[pazymiuSkaicius / 2 - 1];
        int vidurinis2 = nd_[pazymiuSkaicius / 2];
        return ((vidurinis1 + vidurinis2) / 2.0) * 0.4 + egz_ * 0.6;
    }
    else
    {
        return nd_[pazymiuSkaicius / 2] * 0.4 + egz_ * 0.6;
    }
}
//---------------------------------------------------------------------------------------
std::vector<Studentass> Studentass::Nuskaityti(const std::string& filename) {
    std::vector<Studentass> students;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return students; //
    }

    std::string header;
    std::getline(file, header);

    while (true) {
        Studentass student;
        file >> student;

        if (file.fail()) {
            break;
        }

        students.push_back(student);
    }

    file.close();
    return students;
}
//---------------------------------------------------------------------------------------
std::istream& operator>>(std::istream& in, Studentass& student) {
    in >> student.vardas_ >> student.pavarde_;

    if (in.fail()) {
        return in;
    }

    while (true) {
        int grade;
        in >> grade;

        if (in.fail() || in.peek() == '\n' || in.peek() == EOF) {
            student.egz_ = grade;
            break;
        }

        student.nd_.push_back(grade);
    }

    student.galutinis_ = student.skaiciuotiGalutini1();
    student.mediana_ = student.skaiciuotiMediana1();

    return in;
}
//-------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const Studentass& student) {
        out << setw(15) << left << student.vardas_
            << setw(15) << left << student.pavarde_;
        for (const double& ndValue : student.nd_) {
            out << " " << ndValue;
        }
        out<< setw(15) << left << student.egz_;

        out << fixed << setprecision(2) << " " << student.galutinis_
            << " " << student.mediana_;

        return out;
    }
//-------------------------------------------------------------------------------
void spausdinti_(const std::vector<Studentass>& studentai, const std::string& failo_pavad, char choice) {
    std::ofstream outputFile(failo_pavad);

    if (outputFile.is_open()) {
        outputFile << std::setw(15) << std::left << "Vardas"
                   << std::setw(15) << std::left << "Pavarde"
                   << ((choice == 'a') ? "Galutinis (Med)" : "Galutinis (Vid)") << std::endl;
        outputFile << "--------------------------------------------" << std::endl;

        for (const Studentass& studentas : studentai) {
            outputFile << std::setw(15) << std::left << studentas.vardas()
                       << std::setw(15) << std::left << studentas.pavarde()
                       << std::fixed << std::setprecision(2)
                       << ((choice == 'a') ? studentas.mediana() : studentas.galutinis()) << std::endl;
        }

        outputFile.close();
       // std::cout << "Rezultatai irasyti i " << failo_pavad << std::endl;
    } else {
        std::cout << "Nepavyko atidaryti failo" << std::endl;
    }
}
//----------------------------------------------------------------------------------
void isskirstymas111(vector<Studentass>& studentai, vector<Studentass>& geri_studentai, char choice) {
    auto condition = (choice == 'b') ? [](const Studentass& studentas) { return studentas.galutinis() >= 5; }
                                      : [](const Studentass& studentas) { return studentas.mediana() >= 5; };

    auto partition_point = std::partition(studentai.begin(), studentai.end(), condition);

    geri_studentai.insert(geri_studentai.end(),
                          std::make_move_iterator(partition_point),
                          std::make_move_iterator(studentai.end()));

    studentai.erase(partition_point, studentai.end());
}
//---------------------------------------------------------------------------------------
void rikiuoti_(vector<Studentass>& studentai, char sortBy) {
    sort(studentai.begin(), studentai.end(), [sortBy](const Studentass& c, const Studentass& d) {
        if (sortBy == 'a') { // Sort by average
            return c.mediana() < d.mediana();
        }
        if (sortBy == 'b') { // Sort by median
            return c.galutinis() < d.galutinis();
        }
        return c.vardas() < d.vardas();
    });
}
//-----------------------------------------------------------------------------------------
void processStudentData_class(int numStudents, char choice) {
    vector<Studentass> studentai;
    vector<Studentass> bahurai;
    string filename = "stud_" + to_string(numStudents) + ".txt";

    Timer timer;

    timer.reset();
    studentai=Studentass::Nuskaityti(filename);
    cout << timer.elapsed()  << endl;

    timer.reset();
    isskirstymas111(studentai, bahurai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    rikiuoti_(bahurai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    rikiuoti_(studentai, choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    spausdinti_(bahurai, "results_" + to_string(numStudents) + "_1.txt", choice);
    cout  << timer.elapsed()  << endl;

    timer.reset();
    spausdinti_(studentai, "results_" + to_string(numStudents) + "_2.txt", choice);
    cout << timer.elapsed() <<  endl;
}




