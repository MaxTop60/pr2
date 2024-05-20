#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string findMinYearLine(const string& filename) {
    ifstream file(filename);
    int minYear = INT_MAX;
    string minYearLine;

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return "";
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int day, month, year;
        char delimiter;

        if (iss >> day >> delimiter >> month >> delimiter >> year) {
            if (year < minYear) {
                minYear = year;
                minYearLine = line;
            }
        }
        else {
            cerr << "Ошибка чтения даты из файла." << endl;
            return "";
        }
    }

    file.close();
    return minYearLine;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string filename = "dates.txt"; // имя вашего файла с датами
    string minYearLine = findMinYearLine(filename);

    if (!minYearLine.empty()) {
        cout << "Строка с минимальным годом: " << minYearLine << endl;
    }

    return 0;
}