#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

// Function to generate a random matrix
std::vector<std::vector<int>> generateMatrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Random numbers between 0 and 99
        }
    }
    return matrix;
}

// Function to multiply two matrices
std::vector<std::vector<int>> multiplyMatrices1(const std::vector<std::vector<int>> &a,
                                               const std::vector<std::vector<int>> &b) {
    int rows = a.size();
    int cols = b[0].size();
    int common = b.size(); // This should be equal to a[0].size()

    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < common; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

std::vector<std::vector<int>> multiplyMatrices2(const std::vector<std::vector<int>> &a,
                                               const std::vector<std::vector<int>> &b) {
    int rows = a.size();
    int cols = b[0].size();
    int common = b.size(); // This should be equal to a[0].size()

    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < common; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}



int main() {
    srand(time(nullptr)); // Seed the random number generator

    int size1 = 1000; // Set matrix size
    auto matrix1 = generateMatrix(size1, size1);
    auto matrix2 = generateMatrix(size1, size1);
    int size2  =1500;
    auto matrix3 = generateMatrix(size2, size2);
    auto matrix4 = generateMatrix(size2, size2);

    // Multiply the matrices
    auto multipliedResult1 = multiplyMatrices1(matrix1, matrix2);

      // Multiply the matrices
    auto multipliedResult2 = multiplyMatrices2(matrix3, matrix4);

  

    std::cout << "Matrix multiplication and addition complete." << std::endl;
    return 0;
}
