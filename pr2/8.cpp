#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для хранения информации о мониторе
struct Monitor {
    string firmName;
    float screenSize;
    float price;
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем массив структур Monitor с информацией о мониторах
    Monitor monitors[] = {
        {"Firm1", 20, 200}, // Пример информации о мониторах, замените на свою
        {"Firm2", 21, 250},
        {"Firm3", 18, 180},
        {"Firm4", 19, 220},
    };

    // Записываем информацию о мониторах в бинарный файл
    ofstream outFile("monitors.dat", ios::binary);
    outFile.write(reinterpret_cast<char*>(&monitors), sizeof(monitors));
    outFile.close();

    // Считываем информацию из бинарного файла и вычисляем среднюю цену мониторов размером не менее 19 дюймов
    ifstream inFile("monitors.dat", ios::binary);
    Monitor readMonitors[4]; // Предполагаем, что в файле 4 записи, замените на нужное количество

    inFile.read(reinterpret_cast<char*>(&readMonitors), sizeof(readMonitors));
    inFile.close();

    float total_price = 0;
    int count = 0;

    for (const Monitor& monitor : readMonitors) {
        if (monitor.screenSize >= 19) {
            total_price += monitor.price;
            count++;
            // Выводим информацию о мониторе размером не менее 19 дюймов
            cout << "Название Фипмы: " << monitor.firmName << ", Размер: " << monitor.screenSize << " дюймов, Цена: $" << monitor.price << endl;
        }
    }

    if (count > 0) {
        float average_price = total_price / count;
        cout << "Средняя цена мониторов (размер >= 19 дюймов): $" << average_price << endl;
    }
    else {
        cout << "Нет мониторов с размером >= 19 дюймов." << endl;
    }

    return 0;
}