#include <iostream>
#include <fstream>
#include <cctype> // Для использования функции std::toupper()

int main() {
    setlocale(LC_ALL, "Russian");
    // Открываем файл для записи в бинарном режиме
    std::ofstream outFile("input.bin", std::ios::binary);
    if (!outFile) {
        std::cerr << "Невозможно открыть файл!" << std::endl;
        return 1;
    }

    // Просим пользователя ввести символы английского алфавита
    std::cout << "Введите символы английского алфавита (Ctrl+Z для завершения):" << std::endl;
    char ch;
    while (std::cin >> ch) {
        outFile.write(&ch, sizeof(char)); // Записываем символы в файл
    }

    outFile.close(); // Закрываем файл

    // Читаем и выводим символы до изменений из файла
    std::ifstream inFile("input.bin", std::ios::binary);
    if (!inFile) {
        std::cerr << "Невозможно открыть файл!" << std::endl;
        return 1;
    }

    std::cout << "Символы до изменений: ";
    while (inFile.read(&ch, sizeof(char))) {
        std::cout << ch;
    }
    std::cout << std::endl;

    // Преобразуем символы в заглавные и переписываем в другой файл
    inFile.clear();
    inFile.seekg(0, std::ios::beg);
    std::ofstream modifiedFile("modified.bin", std::ios::binary);
    if (!modifiedFile) {
        std::cerr << "Невозможно открыть файл!" << std::endl;
        return 1;
    }

    std::cout << "Символы после изменений: ";
    while (inFile.read(&ch, sizeof(char))) {
        ch = std::toupper(ch); // Преобразуем в заглавные буквы
        std::cout << ch;
        modifiedFile.write(&ch, sizeof(char)); // Записываем в файл
    }
    std::cout << std::endl;

    inFile.close(); // Закрываем файлы
    modifiedFile.close();

    return 0;
}