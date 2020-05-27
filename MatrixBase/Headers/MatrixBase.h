//
// Created by Sam Petrov on 28.05.2020.
//

#ifndef MATRIXBASE_MATRIXBASE_H
#define MATRIXBASE_MATRIXBASE_H

#include <iostream>
#include <stdexcept>

class MatrixBase {
public:
    MatrixBase() = delete;
    void operator *= (int iMult);
    void operator += (MatrixBase& iAdd);
    unsigned int size() const { return m_size; }
    virtual int element(unsigned int i, unsigned int j) const = 0;
    virtual int& element(unsigned int i, unsigned int j) = 0;
    friend std::ostream& operator<< (std::ostream &out, const MatrixBase &iMatrix);
protected:
    explicit MatrixBase(unsigned int iSize) : m_size(iSize) {}
private:
    const unsigned int m_size;
};

#endif //MATRIXBASE_MATRIXBASE_H
