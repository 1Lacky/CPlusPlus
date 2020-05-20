#include <iostream>
#include "BinaryTree.h"

int main() {
    const int SIZE = 9;
    auto array = new int[SIZE]{1, 3, 4, 6, 7, 8, 10, 13, 14};
    auto tree = BinaryTree(array, 0, SIZE - 1);
    tree.insert(5);
    for(int i = 0; i < 15; i++) {
        if(tree.search(i) == nullptr)
            std::cout << "Не найдент элемент "<< i << std::endl;
        else
            std::cout << "Элемент "<< i <<" найден"<< std::endl;
    }
    return 0;
}
