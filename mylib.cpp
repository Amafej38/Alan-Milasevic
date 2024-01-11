#include "mylib.h"

char skaiciavimo_Strategija = 'v';

studentas::studentas() {
    cout << "Ivesk varda: "; cin >> vard;
    cout << "Ivesk pavarde: "; cin >> pav;
    cout << "Kiek pazymiu buvo semestre?";
    int n; cin >> n;
    paz.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Ivesk " << i + 1 << " semestro pazymi: ";
        cin >> paz[i];
    }
    cout << "Ivesk egzamino pazymi: "; cin >> egz;
    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}

studentas::studentas(string v, string p, vector<int> pp, int e) : vard(v), pav(p), paz(pp), egz(e) {
    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}

studentas::studentas(const studentas& temp) : vard(temp.vard), pav(temp.pav), paz(temp.paz), egz(temp.egz) {
    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}

studentas& studentas::operator=(const studentas& temp) {
    if (this == &temp) return *this;
    vard = temp.vard; pav = temp.pav; paz = temp.paz; egz = temp.egz;
    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
    return *this;
}

studentas::~studentas() {
    vard.clear(); pav.clear(); paz.clear();
    egz = 0; rez = 0;
}

void studentas::printas() {
    printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
    for (auto& a : paz) printf("%3d|", a);
    printf("%10d\n", egz);
}

void studentas::printasRez() {
    printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
    printf("%10.2f|\n", rez);
}

void studentas::rezVid() {
    float sum = std::accumulate(paz.begin(), paz.end(), 0.0);
    rez = sum / paz.size() * 0.4 + egz * 0.6;
}

void studentas::rezMed() {
    rez = mediana(paz) * 0.4 + egz * 0.6;
}

double studentas::mediana(vector<int> vec) {
    typedef vector<double>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("negalima skaičiuoti medianos tuščiam vekt");

    sort(vec.begin(), vec.end());

    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid + 1]) / 2.0 : vec[vid] / 1.0;
}