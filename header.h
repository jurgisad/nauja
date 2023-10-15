#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>  
#include <fstream>
#include <random>
#include <chrono>

//-----------------------------------------------
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
using std::sort;
using std::invalid_argument;
using std::numeric_limits;
using std::max;
using std::streamsize;
using std::ofstream;
using std:: cerr;
using std::to_string;

//-----------------------------------------------
struct Studentas
{
    string Vardas, Pavarde;
    vector <int> nd;
    int egz;
    double galutinis, mediana;
};
int generateRandomNumber2(std::mt19937& mt);
double skaiciuotiGalutini(Studentas& studentas);
double skaiciuotiMediana(Studentas& studentas);

void nuskaitytiIsFailo(vector<Studentas>& studentai);

string getValidInputAorB();

string getValidVardasPavarde();

void ivestis(vector<Studentas>& studentai);

bool palyginimas(const Studentas& a, const Studentas& b);

void rikiuoti(vector<Studentas>& studentai);

void spausdinti(vector<Studentas>& studentai, string failo_pavad, char choice);

void ived_tikr(auto &a);

void ived_tikr_a_or_b(char &a);

void ived_tikr_nd(auto &a);

void ived_tikr_egz(int &a);

void generavimas(vector<Studentas>& studentai, int studentuskc);

void isskirstymas(vector<Studentas>& studentai, vector<Studentas>& geri_studentai, vector<Studentas>& blogi_studentai, char choice);
#endif // MYLIB_H_INCLUDED
