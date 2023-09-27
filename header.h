#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::setw;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;

int randint(int nuo, int iki);

double skaiciuotiGalutini(Studentas& studentas);
double skaiciuotiMediana(Studentas& studentas);

struct Studentas{
    string Vardas, Pavarde;
    vector <int> nd;
    int egz;
    double galutinis, mediana;
};

void nuskaitytiIsFailo(vector<Studentas>& studentai);

void ivestis(vector<Studentas>& studentai);

void spausdinti(vector<Studentas>& studentai);

#endif // MYLIB_H_INCLUDED
