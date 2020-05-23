//
// Created by Sam Petrov on 19.05.2020.
//

#include <cassert>
#include <ctime>
#include <random>
#include "MatrixXnX.h"

int MatrixXnX::element(const int i, const int j) const {
    assert((0 <= i && i < Size) && (0 <= j && j < Size));
    return matrix[getIndex(i, j)];
}

void MatrixXnX::setElement(const int i, const int j, const int value) {
    assert((0 <= i && i < Size) && (0 <= j && j < Size));
    matrix[getIndex(i, j)] = value;
}

int MatrixXnX::getIndex(const int i, const int j) const {
    return Size * i + j;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal) {
    std::mt19937 generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for(int i = 0; i < Size; ++i)
        for(int j = 0; j < Size; ++j)
            setElement(i, j, distribution(generator));
}

int MatrixXnX::sumPrincipalDiag() const {
    int sum = 0;
    for(int i = 0; i < Size; ++i) {
        sum += matrix[getIndex(i, i)];
    }
    return sum;
}

int MatrixXnX::sumSecondaryDiag() const {
    int sum = 0;
    for(int i = 0; i < Size; ++i){
        sum += matrix[getIndex(i, Size - i - 1)];
    }
    return sum;
}

int MatrixXnX::productPrincipalDiag() const {
    int product = 1;
    for(int i = 0; i < Size; ++i) {
        product *= matrix[getIndex(i, i)];
    }
    return product;
}

int MatrixXnX::productSecondaryDiag() const {
    int product = 1;
    for(int i = 0; i < Size; ++i){
        product *= matrix[getIndex(i, Size - i - 1)];
    }
    return product;
}

int MatrixXnX::sumRow(const int iRow) const {
    assert(0 <= iRow && iRow < Size);
    int sum = 0;
    for(int j = 0; j < Size; ++j)
        sum += matrix[getIndex(iRow, j)];
    return sum;
}

int MatrixXnX::minColumn(const int iCol) const {
    assert(0 <= iCol && iCol < Size);
    int min =  matrix[getIndex(0, iCol)];
    for(int i = 0; i < Size; ++i){
        if(matrix[getIndex(i, iCol)] < min)
            min = matrix[getIndex(i, iCol)];
    }
    return min;
}

int MatrixXnX::maxColumn(const int iCol) const {
    assert(0 <= iCol && iCol < Size);
    int max =  matrix[getIndex(0, iCol)];
    for(int i = 0; i < Size; ++i){
        if(matrix[getIndex(i, iCol)] > max)
            max = matrix[getIndex(i, iCol)];
    }
    return max;
}

MatrixXnX::MatrixXnX(const int iDim): Size(iDim) {
    matrix = new int[iDim * iDim];
    for(int i = 0; i < Size; ++i)
        for(int j = 0; j < Size; ++j)
            matrix[getIndex(i , j)] = 0;
}

MatrixXnX::~MatrixXnX() {
    delete matrix;
}