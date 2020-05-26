//
// Created by Sam Petrov on 18.05.2020.
//

#include <cassert>
#include <ctime>
#include <random>
#include "Matrix3x3.h"

int Matrix3x3::element(const int i, const int j) const {
    assert(i < SIZE && j < SIZE);
    return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value) {
    matrix[i][j] = value;
}

void  Matrix3x3::fillRandomElements(const int minVal, const int maxVal) {
    std::mt19937 generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            setElement(i, j, distribution(generator));
}

int Matrix3x3::sumPrincipalDiag() const {
    int sum = 0;
    int j = 0;
    for(int i = 0; i < SIZE; ++i) {
        sum += matrix[i][j];
        ++j;
    }
    return sum;
}

int Matrix3x3::sumSecondaryDiag() const {
    int sum = 0;
    int j = SIZE - 1;
    for(int i = 0; i < SIZE; ++i){
        sum += matrix[i][j];
        --j;
    }
    return sum;
}

int Matrix3x3::productPrincipalDiag() const {
    int product = 1;
    int j = 0;
    for(int i = 0; i < SIZE; ++i) {
        product *= matrix[i][j];
        ++j;
    }
    return product;
}

int Matrix3x3::productSecondaryDiag() const {
    int product = 1;
    int j = SIZE - 1;
    for(int i = 0; i < SIZE; ++i){
        product *= matrix[i][j];
        --j;
    }
    return product;
}

int Matrix3x3::sumRow(const int iRow) const {
    int sum = 0;
    for(int j = 0; j < SIZE; ++j)
        sum += matrix[iRow][j];
    return sum;
}

int Matrix3x3::minColumn(const int iCol) const {
    int min =  matrix[0][iCol];
    for(int i = 0; i < SIZE; ++i){
        if(matrix[i][iCol] < min)
            min = matrix[i][iCol];
    }
    return min;
}

int Matrix3x3::maxColumn(const int iCol) const {
    int max =  matrix[0][iCol];
    for(int i = 0; i < SIZE; ++i){
        if(matrix[i][iCol] > max)
            max = matrix[i][iCol];
    }
    return max;
}

Matrix3x3::Matrix3x3() {
    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            matrix[i][j] = 0;
}