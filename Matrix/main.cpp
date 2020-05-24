#include <iostream>
#include <iomanip>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include "LinkedList.h"

void useMatrix3x3() {
    Matrix3x3 m3;

    m3.fillRandomElements(-10, 10);

    for (int i = 0; i < Matrix3x3::Size; ++i) {
        for (int j = 0; j < Matrix3x3::Size; ++j)
            std::cout <<std::setw( 4 )<< m3.element(i, j) << " ";
        std::cout << std::endl;
    }

    std::cout << "Cумма элементов главной диагонали: " << m3.sumPrincipalDiag() << std::endl;
    std::cout << "Cумма элементов побочной диагонали: " << m3.sumSecondaryDiag() << std::endl;
    std::cout << "Произведение элементов главной диагонали: " << m3.productPrincipalDiag() << std::endl;
    std::cout << "Произведение элементов побочной диагонали: " << m3.productSecondaryDiag() << std::endl;

    for (int i = 0; i < Matrix3x3::Size; ++i)
        std::cout << "Сумма элементов в строке " << i << ": " << m3.sumRow(i) << std::endl;
    for (int i = 0; i < Matrix3x3::Size; ++i)
        std::cout << "Минимальный элемент в столбце " << i << ": " << m3.minColumn(i) << std::endl;
    for (int i = 0; i < Matrix3x3::Size; ++i)
        std::cout << "Максимальный элемент в столбце " << i << ": " << m3.maxColumn(i) << std::endl;
}

void useMatrixXnX() {
    MatrixXnX mX(4);

    mX.fillRandomElements(-10, 10);

    for (int i = 0; i < mX.Size; ++i) {
        for (int j = 0; j < mX.Size; ++j)
            std::cout <<std::setw( 4 )<< mX.element(i, j) << " ";
        std::cout << std::endl;
    }

    std::cout << "Cумма элементов главной диагонали: " << mX.sumPrincipalDiag() << std::endl;
    std::cout << "Cумма элементов побочной диагонали: " << mX.sumSecondaryDiag() << std::endl;
    std::cout << "Произведение элементов главной диагонали: " << mX.productPrincipalDiag() << std::endl;
    std::cout << "Произведение элементов побочной диагонали: " << mX.productSecondaryDiag() << std::endl;

    for (int i = 0; i < mX.Size; ++i)
        std::cout << "Сумма элементов в строке " << i << ": " << mX.sumRow(i) << std::endl;
    for (int i = 0; i < mX.Size; ++i)
        std::cout << "Минимальный элемент в столбце " << i << ": " << mX.minColumn(i) << std::endl;
    for (int i = 0; i < mX.Size; ++i)
        std::cout << "Максимальный элемент в столбце " << i << ": " << mX.maxColumn(i) << std::endl;
}

void useLinkedList() {
    LinkedList list;

    for(int i = 0; i < 17 ;++i)
        list.addItem(i % 10);

    for(int i = 1; i < 21 ;++i) {
        auto result = list.searchItem(i);
        if(result == nullptr)
            std::cout << "Не найдент элемент № "<< i << std::endl;
        else
            std::cout << "Элемент № "<< i << " = " << result->getData() << std::endl;
    }

    list.deleteDuplicates();

    for(int i = 1; i < 21 ;++i) {
        auto result = list.searchItem(i);
        if(result == nullptr)
            std::cout << "Не найдент элемент № "<< i << std::endl;
        else
            std::cout << "Элемент № "<< i << " = " << result->getData() << std::endl;
    }
}

int main() {
    useMatrix3x3();
    useMatrixXnX();
    useLinkedList();
    return 0;
}
