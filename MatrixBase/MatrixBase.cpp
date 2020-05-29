//
// Created by Sam Petrov on 28.05.2020.
//

#include "MatrixBase.h"
#include <cassert>
#include <iomanip>

void MatrixBase::operator*=(int iMult) {
    for (int i = 0; i < m_size; ++i)
        for (int j = 0; j < m_size; ++j)
            element(i, j) *= iMult;
}

void MatrixBase::operator+=(MatrixBase& iAdd) {
    assert(iAdd.size() == m_size);
    for (int i = 0; i < iAdd.m_size; ++i)
        for (int j = 0; j < iAdd.m_size; ++j)
            element(i, j) += iAdd.element(i,j);
}

std::ostream &operator<<(std::ostream &out, const MatrixBase &iMatrix) {
    for (int i = 0; i < iMatrix.m_size; ++i) {
        for (int j = 0; j < iMatrix.m_size; ++j) {
            out << std::setw( 3 )<<iMatrix.element(i, j);
        }
        out<<std::endl;
    }
    return out;
}