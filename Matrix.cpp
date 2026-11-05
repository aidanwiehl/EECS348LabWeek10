#include "Matrix.h"
#include <iomanip>
#include <stdexcept>

Matrix::Matrix() : N(0) {}

Matrix::Matrix(int size) : N(size), data(size, std::vector<int>(size, 0)) {}

Matrix::Matrix(const std::vector<std::vector<int>>& matData) {
    data = matData;
    N = matData.size();
}

int Matrix::getSize() const {
    return N;
}

int Matrix::getElement(int r, int c) const {
    if (r < 0 || r >= N || c < 0 || c >= N) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[r][c];
}

void Matrix::setElement(int r, int c, int val) {
    if (r < 0 || r >= N || c < 0 || c >= N) {
        throw std::out_of_range("Index out of bounds");
    }
    data[r][c] = val;
}

void Matrix::display() const {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << data[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (N != other.N) {
        throw std::invalid_argument("Matrices must be of the same size for addition.");
    }
    Matrix result(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (N != other.N) {
        throw std::invalid_argument("Matrices must be of the same size for multiplication.");
    }
    Matrix result(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void Matrix::diagonalSums() const {
    int mainSum = 0;
    int secSum = 0;
    for (int i = 0; i < N; ++i) {
        mainSum += data[i][i];
        secSum += data[i][N - 1 - i];
    }
    std::cout << "Main diagonal sum: " << mainSum << std::endl;
    std::cout << "Secondary diagonal sum: " << secSum << std::endl;
}

Matrix Matrix::swapRows(int r1, int r2) const {
    if (r1 < 0 || r1 >= N || r2 < 0 || r2 >= N) {
        throw std::out_of_range("Row indices out of bounds");
    }
    Matrix result = *this; // Pass by value (copies matrix)
    std::vector<int> temp = result.data[r1];
    result.data[r1] = result.data[r2];
    result.data[r2] = temp;
    return result;
}

Matrix Matrix::swapColumns(int c1, int c2) const {
    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N) {
        throw std::out_of_range("Column indices out of bounds");
    }
    Matrix result = *this;
    for (int i = 0; i < N; ++i) {
        int temp = result.data[i][c1];
        result.data[i][c1] = result.data[i][c2];
        result.data[i][c2] = temp;
    }
    return result;
}

Matrix Matrix::updateElement(int r, int c, int val) const {
    if (r < 0 || r >= N || c < 0 || c >= N) {
        throw std::out_of_range("Indices out of bounds");
    }
    Matrix result = *this;
    result.data[r][c] = val;
    return result;
}