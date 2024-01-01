#ifndef ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED

#include <string>

class Zmogus
{
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    Zmogus() : vardas_(""), pavarde_("") {}

    virtual ~Zmogus() {}

    virtual std::string vardas() const
    {
        return vardas_;
    }

    virtual std::string pavarde() const
    {
        return pavarde_;
    }
};

#endif // ZMOGUS_H_INCLUDED
