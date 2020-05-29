//
// Created by Sam Petrov on 20.05.2020.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include "TreeNode.h"

class BinaryTree{
public:
    BinaryTree(int* array, const int start, const int end);
    ~BinaryTree();

    TreeNode* search(int data) const;
    void insert(int data);
private:
    static TreeNode* search(TreeNode* node, int data);
    static TreeNode* insert(TreeNode* node, int data);
    static TreeNode* CreateMinimalBST(const int* array, const int start, const int end);

    static void swap(int* a, int* b);
    static int section(int* arr, const int start,const int end);
    static void quickSort(int* arr, const int start, const int end);

    TreeNode* root = nullptr;
};

#endif //BINARYTREE_BINARYTREE_H
