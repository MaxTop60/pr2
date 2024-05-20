#include <iostream>
#include <fstream>
#include <vector>

int main() {
    setlocale(LC_ALL, "Russian");
    // Открываем файл a.txt для чтения
    std::ifstream inputFile("a.txt");

    // Проверяем, удалось ли открыть файл
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл a.txt" << std::endl;
        return 1; // Возвращаем код ошибки, если не удалось открыть файл
    }

    double number;
    int zeroCount = 0; // Переменная для подсчета количества нулевых элементов
    double positiveSum = 0.0; // Переменная для хранения суммы положительных элементов

    // Читаем числа из файла, пока не достигнем конца файла
    while (inputFile >> number) {
        // Проверяем, является ли текущее число нулем
        if (number == 0) {
            zeroCount++; // Увеличиваем счетчик нулевых элементов
        }
        else if (number > 0) {
            positiveSum += number; // Добавляем положительное число к сумме положительных элементов
        }
    }

    // Закрываем файл
    inputFile.close();

    // Выводим результаты подсчетов
    std::cout << "Количество нулевых элементов: " << zeroCount << std::endl;
    std::cout << "Сумма положительных элементов: " << positiveSum << std::endl;

    return 0;
}