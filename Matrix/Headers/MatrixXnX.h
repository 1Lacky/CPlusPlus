//
// Created by Sam Petrov on 19.05.2020.
//

#ifndef MATRIX_MATRIXXNX_H
#define MATRIX_MATRIXXNX_H

class MatrixXnX{
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
    MatrixXnX(const int);
    ~MatrixXnX();

    const int SIZE;
private:
    int **matrix;
};
#endif //MATRIX_MATRIXXNX_H
