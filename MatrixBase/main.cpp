#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

int main() {
    Matrix2D secondMatrix2D, firtsMatrix2D;
    Matrix3D secondMatrix3D, firtsMatrix3D;

    std::cout<<"matrix2D: "<< std::endl << firtsMatrix2D << std::endl << secondMatrix2D << std::endl;
    firtsMatrix2D *= 2;
    std::cout<<"matrix2D * 2: "<< std::endl << firtsMatrix2D << std::endl;
    firtsMatrix2D += secondMatrix2D;
    std::cout<<"matrix2D + matrix2D: "<< std::endl << firtsMatrix2D << std::endl;

    std::cout<<"matrix3D: "<< std::endl << firtsMatrix3D << std::endl << secondMatrix3D << std::endl;
    secondMatrix3D *= 3;
    std::cout<<"matrix3D * 3: "<< std::endl << secondMatrix3D << std::endl;
    firtsMatrix3D += secondMatrix3D;
    std::cout<<"matrix3D + matrix3D: "<< std::endl << firtsMatrix3D << std::endl;

    return 0;
}