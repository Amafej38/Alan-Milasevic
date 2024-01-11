#include "mylib.h"
#include <chrono>
#include <locale>
#include <cstdlib>
#include <cassert> 

void printDuration(const std::string& task, const std::chrono::milliseconds& duration) {
    std::cout << task << " užtruko: " << duration.count() << " ms" << std::endl;
}

void readDataFromFile(const std::string& fileName, std::vector<studentas>& grupe) {
    auto startTime = std::chrono::high_resolution_clock::now();

    std::ifstream input(fileName);
    assert(input.is_open()); 

    std::string line;
    getline(input, line);

    while (getline(input, line)) {
        std::istringstream iss(line);
        std::string vard, pav;
        std::vector<int> paz;
        int egz;
        iss >> vard >> pav;

        for (int i = 0; i < 15; i++) {
            int nd;
            iss >> nd;
            paz.push_back(nd);
        }

        iss >> egz;

        studentas K(vard, pav, paz, egz);
        grupe.push_back(K);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    printDuration("Duomenų nuskaitymas iš failo", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime));
}

void sortStudents(std::vector<studentas>& grupe, std::vector<studentas>& silpni, std::vector<studentas>& stipri) {
    auto startTime = std::chrono::high_resolution_clock::now();

    for (const auto& student : grupe) {
        if (student.getRez() < 5.0)
            silpni.push_back(student);
        else
            stipri.push_back(student);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    printDuration("Studentų rūšiavimas", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime));
}

void writeToFile(const std::string& fileName, const std::vector<studentas>& students) {
    std::ofstream outputFile(fileName);
    for (const auto& student : students) {
        outputFile << student.getVardas() << " " << student.getPavarde() << " " << student.getRez() << std::endl;
    }
    outputFile.close();
}

int main() {
    setlocale(LC_ALL, "Lithuanian");
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Kaip skaicuoti galutini? v/m ";
    std::cin >> skaiciavimo_Strategija;

    std::cout << "Txt failo pasirinkimas - 10000 arba 100000 arba 1000000. Jusu ivedimas: ";
    int fileChoice;
    std::cin >> fileChoice;

    std::string fileName;
    switch (fileChoice) {
    case 10000:
        fileName = "studentai10000.txt.txt";
        break;
    case 100000:
        fileName = "studentai100000.txt.txt";
        break;
    case 1000000:
        fileName = "studentai1000000.txt.txt";
        break;
    default:
        std::cerr << "Invalid file choice." << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<studentas> grupe, silpni, stipri;

    readDataFromFile(fileName, grupe);
    sortStudents(grupe, silpni, stipri);

    writeToFile("silpni.txt", silpni);
    writeToFile("stipri.txt", stipri);

    system("pause");
    return 0;
}