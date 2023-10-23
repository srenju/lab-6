#include <iostream>
#include <fstream>
#include <iomanip>
const static int MAX_SIZE = 100;
const static std::string FILENAME = "matrix_input.txt";
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, int matrixNumber);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size, const std::string &label);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;
    std::cout << "Saurav Renju\n";
    std::cout << "Lab #6: Matrix manipulation\n\n";
    readMatrixFromFile(matrix1, size, 1);
    readMatrixFromFile(matrix2, size, 2);
    printMatrix(matrix1, size, "Matrix A:");
    std::cout << "\n";
    printMatrix(matrix2, size, "Matrix B:");
    std::cout << "\n";
    addMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size, "Matrix Sum (A + B):");
    std::cout << "\n";
    multiplyMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size, "Matrix Product (A * B):");
    std::cout << "\n";
    subtractMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size, "Matrix Difference (A - B):");
    return 0;
}
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, int matrixNumber) {
    std::ifstream inFile(FILENAME);
    if (inFile.is_open()) {
        inFile >> size;
        for (int m = 1; m <= matrixNumber; m++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    inFile >> matrix[i][j];
                }
            }
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file " << FILENAME << std::endl;
    }
}
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size, const std::string &label) {
    std::cout << label << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

