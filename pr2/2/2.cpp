#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file1("a1.txt");
    std::ifstream file2("a2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Не удалось открыть один из файлов" << std::endl;
        return 1;
    }

    double num1, num2;
    double product = 1.0;

    // Считываем по одному числу из каждого файла и перемножаем отрицательные числа
    while (file1 >> num1 && file2 >> num2) {
        if (num1 < 0 && num2 < 0) {
            product *= num1 * num2;
        }
    }

    file1.close();
    file2.close();

    std::cout << "Произведение отрицательных элементов двух файлов: " << product << std::endl;

    return 0;
}