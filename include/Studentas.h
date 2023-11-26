#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
#include "header.h"

class Studentass {
private:
    std::string vardas_;
    std::string pavarde_;
    double egz_;
    std::vector<double> nd_;
    double galutinis_, mediana_;

public:
    Studentass(const std::string& vardas, const std::string& pavarde, double egz, const std::vector<double>& nd)
    : vardas_(vardas), pavarde_(pavarde), egz_(egz), nd_(nd) {
    galutinis_ = skaiciuotiGalutini1();
    mediana_ = skaiciuotiMediana1();
}

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double egz() const { return egz_; }
    inline const std::vector<double>& nd() const { return nd_; }
    inline double galutinis() const { return galutinis_; }
    inline double mediana() const { return mediana_; }

    double skaiciuotiGalutini1();
    double skaiciuotiMediana1();
    static std::vector<Studentass> Nuskaityti(const std::string& filename);
};
void spausdinti_(const std::vector<Studentass>& studentai, const std::string& failo_pavad, char choice);
void isskirstymas111(vector<Studentass>& studentai, vector<Studentass>& geri_studentai, char choice);
void rikiuoti_(vector<Studentass>& studentai, char sortBy);
void processStudentData_class(int numStudents, char choice);
void nuskaitytiIsFailo(std::vector<Studentass>& studentai, const std::string& failas);


#endif // STUDENTAS_H_INCLUDED
