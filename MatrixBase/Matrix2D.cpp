//
// Created by Sam Petrov on 28.05.2020.
//

#include "Matrix2D.h"

Matrix2D::Matrix2D(): MatrixBase(height) {
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < height; ++j)
            matrix[i][j] = i * height + j + 1;
};