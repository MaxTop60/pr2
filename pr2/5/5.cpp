#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Patient {
    string lastName;
    string firstName;
    string middleName;
    char gender;
    string nationality;
    int height;
    int weight;
    string birthDate;
    string phoneNumber;
    string address;
    int hospitalNumber;
    string department;
    int medicalCardNumber;
    string diagnosis;
    string bloodGroup;
};

void createPatientFile() {
    ofstream file("Пациент.txt");
    file << "Фамилия;Имя;Отчество;Пол;Национальность;Рост;Вес;Дата рождения;Номер телефона;Домашний адрес;Номер больницы;Отделение;Номер медицинской карты;Диагноз;Группа крови\n";
    file.close();
}

void addPatient(const Patient& patient) {
    ofstream file("Пациент.txt", ios::app);
    file << patient.lastName << ";" << patient.firstName << ";" << patient.middleName << ";" << patient.gender << ";" << patient.nationality << ";" << patient.height << ";" << patient.weight << ";" << patient.birthDate << ";" << patient.phoneNumber << ";" << patient.address << ";" << patient.hospitalNumber << ";" << patient.department << ";" << patient.medicalCardNumber << ";" << patient.diagnosis << ";" << patient.bloodGroup << "\n";
    file.close();
}

void printPatientsFromDepartment(const string& department) {
    ifstream file("Пациент.txt");
    string line;
    cout << "Пациенты из отделения " << department << ":\n";
    while (getline(file, line)) {
        if (line.find(department) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    

    // Вывод данных пациентов из 18 отделения
    printPatientsFromDepartment("Отделение 18");

    return 0;
}