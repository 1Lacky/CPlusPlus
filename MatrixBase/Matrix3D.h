//
// Created by Sam Petrov on 28.05.2020.
//

#ifndef MATRIXBASE_MATRIX3D_H
#define MATRIXBASE_MATRIX3D_H

#include "MatrixBase.h"

class Matrix3D: public MatrixBase {
public:
    Matrix3D();
    int element(unsigned int i, unsigned int j) const override { return matrix[i][j]; };
    int& element(unsigned int i, unsigned int j) override { return matrix[i][j]; };

private:
    static constexpr int height = 3;
    int matrix[height][height];
};
#endif //MATRIXBASE_MATRIX3D_H