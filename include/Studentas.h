#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED
#include "header.h"
#include "timer.h"

class Studentass
{
private:
    std::string vardas_;
    std::string pavarde_;
    int egz_;
    std::vector<int> nd_;
    double galutinis_, mediana_;

public:
    Studentass(const std::string& vardas, const std::string& pavarde, const std::vector<int>& nd, int egz)
        : vardas_(vardas), pavarde_(pavarde), egz_(egz), nd_(nd)
    {
        galutinis_ = skaiciuotiGalutini1();
        mediana_ = skaiciuotiMediana1();
    };
    Studentass(const Studentass& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), egz_(other.egz_), nd_(other.nd_),
          galutinis_(other.galutinis_), mediana_(other.mediana_)
    {
    }
    Studentass& operator=(const Studentass& other)
    {
        if (this != &other)
        {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egz_ = other.egz_;
            nd_ = other.nd_;
            galutinis_ = other.galutinis_;
            mediana_ = other.mediana_;
        }
        return *this;
    }
    Studentass() : egz_(0), galutinis_(0), mediana_(0) {}
    inline std::string vardas() const
    {
        return vardas_;
    }
    inline std::string pavarde() const
    {
        return pavarde_;
    }
    inline int egz() const
    {
        return egz_;
    }
    inline const std::vector<int>& nd() const
    {
        return nd_;
    }
    inline double galutinis() const
    {
        return galutinis_;
    }
    inline double mediana() const
    {
        return mediana_;
    }

    double skaiciuotiGalutini1();
    double skaiciuotiMediana1();
    static std::vector<Studentass> Nuskaityti(const std::string& filename);
    ~Studentass() {}
    //std::cout << "Destructor called for " << vardas_ << " " << pavarde_ << std::endl;}
    friend std::istream& operator>>(std::istream& in, Studentass& student);
    friend std::ostream& operator<<(std::ostream& out, const Studentass& student);
};
void spausdinti_(const std::vector<Studentass>& studentai, const std::string& failo_pavad, char choice);
void isskirstymas111(vector<Studentass>& studentai, vector<Studentass>& geri_studentai, char choice);
void rikiuoti_(vector<Studentass>& studentai, char sortBy);
void processStudentData_class(int numStudents, char choice);



#endif // STUDENTAS_H_INCLUDED
