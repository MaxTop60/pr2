#include <iostream>
#include <fstream>
#include <limits>

int main() {
    std::ifstream inputFile("numbers.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }

    int number;
    int minPositiveOnEvenPosition = std::numeric_limits<int>::max(); // Начальное значение - максимальное целое число

    int position = 1; // Начинаем считать позиции с 1
    while (inputFile >> number) {
        // Проверяем, является ли текущая позиция четной и число положительным
        if (position % 2 == 0 && number > 0) {
            // Если число меньше текущего минимального положительного на четной позиции, обновляем минимум
            if (number < minPositiveOnEvenPosition) {
                minPositiveOnEvenPosition = number;
            }
        }
        position++;
    }

    inputFile.close();

    if (minPositiveOnEvenPosition == std::numeric_limits<int>::max()) {
        std::cout << "В файле нет положительных чисел на четных позициях" << std::endl;
    }
    else {
        std::cout << "Наименьшее положительное число на четных позициях: " << minPositiveOnEvenPosition << std::endl;
    }

    return 0;
}