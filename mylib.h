#pragma once

#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::cerr;
using std::endl;

extern char skaiciavimo_Strategija;
extern string failoVardas;

class studentas {
    string vard, pav;
    vector<int> paz;
    int egz;
    float rez;

public:
    studentas();
    studentas(string v, string p, vector<int> pp, int e);
    studentas(const studentas& temp);
    studentas& operator=(const studentas& temp);
    ~studentas();

    inline string getVardas() const { return vard; }
    inline string getPavarde() const { return pav; }
    inline float getRez() const { return rez; }

    inline void setVardas(string t) { vard = t; }

    void printas();
    void printasRez();
    void rezVid();
    void rezMed();
    double mediana(vector<int> vec);
};