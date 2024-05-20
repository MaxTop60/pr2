#include <iostream>
#include <fstream>
#include <cctype> // Для функции std::tolower
#include <string>
int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Не удалось открыть файлы" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Проходимся по каждому символу в строке
        for (char& c : line) {
            // Проверяем, является ли символ большой латинской буквой
            if (std::isupper(c)) {
                // Заменяем большую букву на маленькую
                c = std::tolower(c);
            }
        }
        // Записываем модифицированную строку в выходной файл
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Файл успешно обработан" << std::endl;

    return 0;
}