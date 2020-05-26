//
// Created by Sam Petrov on 18.05.2020.
//

#ifndef MATRIX_MATRIX3X3_H
#define MATRIX_MATRIX3X3_H

class Matrix3x3{
public:
    int element(const int, const int) const;
    void setElement(const int, const int, const int);
    void fillRandomElements(const int, const int);
    int sumPrincipalDiag()const;
    int sumSecondaryDiag() const;
    int productPrincipalDiag() const;
    int productSecondaryDiag() const;
    int sumRow(const int) const;
    int minColumn(const int) const;
    int maxColumn(const int) const;
    Matrix3x3();

    static constexpr int SIZE = 3;
private:
    int matrix[SIZE][SIZE];
};
#endif //MATRIX_MATRIX3X3_H
