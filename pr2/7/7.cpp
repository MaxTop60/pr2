#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функция для чтения матриц из файла
vector<vector<double>> readMatricesFromFile(const string& filename, int k, int n) {
    ifstream file(filename);
    vector<vector<double>> matrices(k, vector<double>(n + 1));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            file >> matrices[i][j];
        }
    }

    file.close();
    return matrices;
}

// Функция для чтения векторов из файла
vector<vector<double>> readVectorsFromFile(const string& filename, int k, int n) {
    ifstream file(filename);
    vector<vector<double>> vectors(k, vector<double>(n));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> vectors[i][j];
        }
    }

    file.close();
    return vectors;
}

// Функция для вывода матриц и векторов на экран
void printSystem(const vector<vector<double>>& matrices, const vector<vector<double>>& vectors) {
    int k = matrices.size();
    int n = matrices[0].size() - 1;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrices[i][j] << "x" << j + 1;
            if (j < n - 1) cout << " + ";
        }
        cout << " = " << matrices[i][n] << "\tResult: " << vectors[i][0] << endl;
    }
}

// Функция для добавления новых матриц в файл
void addMatricesToFile(const string& filename, const vector<vector<double>>& matrices) {
    ofstream file(filename, ios::app);

    for (const auto& row : matrices) {
        for (double val : row) {
            file << val << " ";
        }
        file << endl;
    }

    file.close();
}

// Функция для удаления ненужной информации из файла
void removeDataFromFile(const string& filename, int rowsToRemove) {
    ifstream fileIn(filename);
    ofstream fileOut("temp.txt");

    string line;
    int count = 0;

    while (getline(fileIn, line)) {
        if (count >= rowsToRemove) {
            fileOut << line << endl;
        }
        count++;
    }

    fileIn.close();
    fileOut.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

int main() {
    setlocale(LC_ALL, "Russian");
    string matrixFilename = "matrices.txt";
    string vectorFilename = "vectors.txt";
    int k = 3; // Замените на нужное количество матриц/векторов
    int n = 2; // Замените на нужный размер матрицы

    vector<vector<double>> matrices = readMatricesFromFile(matrixFilename, k, n);
    vector<vector<double>> vectors = readVectorsFromFile(vectorFilename, k, n);

    cout << "Original system of equations and results:" << endl;
    printSystem(matrices, vectors);

    // Пример добавления новых матриц в файл
    vector<vector<double>> newMatrices = { {1, 2, 3}, {4, 5, 6} };
    addMatricesToFile(matrixFilename, newMatrices);

    // Пример удаления ненужной информации из файла
    removeDataFromFile(vectorFilename, 2); // Удалить первые два вектора из файла векторов

    return 0;
}