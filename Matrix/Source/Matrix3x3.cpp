//
// Created by Sam Petrov on 18.05.2020.
//

#include <cassert>
#include <ctime>
#include <random>
#include "Matrix3x3.h"

int Matrix3x3::element(const int i, const int j) const {
    assert((0 <= i && i < Size) && (0 <= j && j < Size));
    return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value) {
    assert((0 <= i && i < Size) && (0 <= j && j < Size));
    matrix[i][j] = value;
}

void  Matrix3x3::fillRandomElements(const int minVal, const int maxVal) {
    std::mt19937 generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for(int i = 0; i < Size; ++i)
        for(int j = 0; j < Size; ++j)
            setElement(i, j, distribution(generator));
}

int Matrix3x3::sumPrincipalDiag() const {
    int sum = 0;
    for(int i = 0; i < Size; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

int Matrix3x3::sumSecondaryDiag() const {
    int sum = 0;
    for(int i = 0; i < Size; ++i){
        sum += matrix[i][Size - i - 1];
    }
    return sum;
}

int Matrix3x3::productPrincipalDiag() const {
    int product = 1;
    for(int i = 0; i < Size; ++i) {
        product *= matrix[i][i];
    }
    return product;
}

int Matrix3x3::productSecondaryDiag() const {
    int product = 1;
    for(int i = 0; i < Size; ++i){
        product *= matrix[i][Size - i - 1];
    }
    return product;
}

int Matrix3x3::sumRow(const int iRow) const {
    assert(0 <= iRow && iRow < Size);
    int sum = 0;
    for(int j = 0; j < Size; ++j)
        sum += matrix[iRow][j];
    return sum;
}

int Matrix3x3::minColumn(const int iCol) const {
    assert(0 <= iCol && iCol < Size);
    int min =  matrix[0][iCol];
    for(int i = 0; i < Size; ++i){
        if(matrix[i][iCol] < min)
            min = matrix[i][iCol];
    }
    return min;
}

int Matrix3x3::maxColumn(const int iCol) const {
    assert(0 <= iCol && iCol < Size);
    int max =  matrix[0][iCol];
    for(int i = 0; i < Size; ++i){
        if(matrix[i][iCol] > max)
            max = matrix[i][iCol];
    }
    return max;
}

Matrix3x3::Matrix3x3() {
    for(int i = 0; i < Size; ++i)
        for(int j = 0; j < Size; ++j)
            matrix[i][j] = 0;
}