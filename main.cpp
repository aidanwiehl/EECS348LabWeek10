#include <iostream>
#include <fstream>
#include <vector>
#include "Matrix.h"

int main() {
    std::string filename;
    std::cout << "Enter input filename: ";
    std::cin >> filename;

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    int N;
    if (!(inFile >> N)) {
        std::cerr << "Error reading matrix size N." << std::endl;
        return 1;
    }

    // Read Matrix A
    std::vector<std::vector<int>> dataA(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inFile >> dataA[i][j];
        }
    }

    // Read Matrix B
    std::vector<std::vector<int>> dataB(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inFile >> dataB[i][j];
        }
    }
    inFile.close();

    Matrix A(dataA);
    Matrix B(dataB);

    // 1. Display Matrices A and B
    std::cout << "\nMatrix A:\n";
    A.display();

    std::cout << "\nMatrix B:\n";
    B.display();

    // 2. Addition using operator overloading (A + B)
    std::cout << "\nA + B:\n";
    Matrix sumMat = A + B;
    sumMat.display();

    // 3. Multiplication using operator overloading (A * B)
    std::cout << "\nA * B:\n";
    Matrix prodMat = A * B;
    prodMat.display();

    // 4. Diagonal sums
    std::cout << "\nDiagonal sums for Matrix A:\n";
    A.diagonalSums();

    // 5. Swap rows (using rows 0 and 2 as in sample output)
    std::cout << "\nProblem 5 - Rows 0 and 2 swapped:\n";
    Matrix swappedRowsMat = A.swapRows(0, 2);
    swappedRowsMat.display();

    // 6. Swap columns (using columns 0 and 2 as in sample output)
    std::cout << "\nProblem 6 - Columns 0 and 2 swapped:\n";
    Matrix swappedColsMat = A.swapColumns(0, 2);
    swappedColsMat.display();

    // 7. Update matrix element (row 1, col 2, value 99 as in sample output)
    std::cout << "\nProblem 7 - Updated matrix:\n";
    Matrix updatedMat = A.updateElement(1, 2, 99);
    updatedMat.display();

    return 0;
}