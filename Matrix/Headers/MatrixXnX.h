//
// Created by Sam Petrov on 19.05.2020.
//

#ifndef MATRIX_MATRIXXNX_H
#define MATRIX_MATRIXXNX_H

class MatrixXnX{
public:
    MatrixXnX(const int iDim);
    int getIndex(const int i, const int j) const;
    int element(const int i, const int j) const;
    void setElement(const int i, const int j, const int value);
    void fillRandomElements(const int minVal, const int maxVal);
    int sumPrincipalDiag()const;
    int sumSecondaryDiag() const;
    int productPrincipalDiag() const;
    int productSecondaryDiag() const;
    int sumRow(const int iRow) const;
    int minColumn(const int iCol) const;
    int maxColumn(const int iCol) const;
    ~MatrixXnX();

    const int Size;
private:
    int *matrix;
};
#endif //MATRIX_MATRIXXNX_H
