#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для хранения данных о покупке
struct Purchase {
    string name;
    string date;
    float totalCost;
    float discountPercent;
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание структуры покупки
    Purchase purchase = { "Иванов И.И.", "22.04.2024", 6000, 10 };

    // Запись структуры в бинарный файл
    ofstream file("purchase.bin", ios::binary);
    file.write(reinterpret_cast<char*>(&purchase), sizeof(Purchase));
    file.close();

    // Чтение структуры из бинарного файла
    ifstream readFile("purchase.bin", ios::binary);
    Purchase readPurchase;
    readFile.read(reinterpret_cast<char*>(&readPurchase), sizeof(Purchase));
    readFile.close();

    // Вывод данных до изменения
    cout << "До изменения:\n";
    cout << "Фамилия и инициалы: " << readPurchase.name << endl;
    cout << "Дата покупки: " << readPurchase.date << endl;
    cout << "Общая стоимость: " << readPurchase.totalCost << " руб." << endl;
    cout << "Процент скидки: " << readPurchase.discountPercent << "%" << endl;

    // Если общая стоимость равна или больше 5000 руб., увеличиваем процент скидки на 5%
    if (readPurchase.totalCost >= 5000) {
        readPurchase.discountPercent += 5;
    }

    // Запись обновленной структуры в файл
    ofstream writeFile("purchase.bin", ios::binary);
    writeFile.write(reinterpret_cast<char*>(&readPurchase), sizeof(Purchase));
    writeFile.close();

    // Чтение и вывод обновленной структуры
    ifstream readFileAgain("purchase.bin", ios::binary);
    Purchase updatedPurchase;
    readFileAgain.read(reinterpret_cast<char*>(&updatedPurchase), sizeof(Purchase));
    readFileAgain.close();

    // Вывод данных после изменения
    cout << "\nПосле изменения:\n";
    cout << "Фамилия и инициалы: " << updatedPurchase.name << endl;
    cout << "Дата покупки: " << updatedPurchase.date << endl;
    cout << "Общая стоимость: " << updatedPurchase.totalCost << " руб." << endl;
    cout << "Процент скидки: " << updatedPurchase.discountPercent << "%" << endl;

    return 0;
}